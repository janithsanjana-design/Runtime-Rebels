#include "Repositories.h"
#include "Db.h"

namespace VehicleRentalSystem
{
	// ---------------------------------------------------------------- helpers

	static String^ Str(MySqlDataReader^ r, String^ column)
	{
		return Convert::ToString(r[column]);
	}

	static int Int(MySqlDataReader^ r, String^ column)
	{
		return Convert::ToInt32(r[column]);
	}

	static Decimal Dec(MySqlDataReader^ r, String^ column)
	{
		return Convert::ToDecimal(r[column]);
	}

	static DateTime Date(MySqlDataReader^ r, String^ column)
	{
		return Convert::ToDateTime(r[column]);
	}

	/// Adds the owner, or updates the existing owner with the same NIC. Returns the owner id.
	static int SaveOwner(MySqlConnection^ c, Owner^ o)
	{
		MySqlCommand^ find = Db::Command(c, "SELECT id FROM owners WHERE nic = @nic");
		Db::Param(find, "@nic", o->Nic);
		Object^ found = find->ExecuteScalar();

		String^ sql = (found != nullptr)
			? "UPDATE owners SET name=@name, phone=@phone, address=@address, bank_account=@bank WHERE nic=@nic"
			: "INSERT INTO owners (name, nic, phone, address, bank_account) VALUES (@name, @nic, @phone, @address, @bank)";

		MySqlCommand^ cmd = Db::Command(c, sql);
		Db::Param(cmd, "@name", o->Name);
		Db::Param(cmd, "@nic", o->Nic);
		Db::Param(cmd, "@phone", o->Phone);
		Db::Param(cmd, "@address", o->Address);
		Db::Param(cmd, "@bank", o->BankAccount);
		cmd->ExecuteNonQuery();

		return (found != nullptr) ? Convert::ToInt32(found) : Convert::ToInt32(cmd->LastInsertedId);
	}

	/// Adds the customer, or updates the existing customer with the same NIC. Returns the customer id.
	static int SaveCustomer(MySqlConnection^ c, Customer^ cu)
	{
		MySqlCommand^ find = Db::Command(c, "SELECT id FROM customers WHERE nic = @nic");
		Db::Param(find, "@nic", cu->Nic);
		Object^ found = find->ExecuteScalar();

		String^ sql = (found != nullptr)
			? "UPDATE customers SET name=@name, phone=@phone, address=@address WHERE nic=@nic"
			: "INSERT INTO customers (name, nic, phone, address) VALUES (@name, @nic, @phone, @address)";

		MySqlCommand^ cmd = Db::Command(c, sql);
		Db::Param(cmd, "@name", cu->Name);
		Db::Param(cmd, "@nic", cu->Nic);
		Db::Param(cmd, "@phone", cu->Phone);
		Db::Param(cmd, "@address", cu->Address);
		cmd->ExecuteNonQuery();

		return (found != nullptr) ? Convert::ToInt32(found) : Convert::ToInt32(cmd->LastInsertedId);
	}

	// ---------------------------------------------------------------- vehicles

	static String^ VehicleSelect()
	{
		return
		"SELECT v.id, v.plate_number, v.vehicle_type, v.brand, v.model, v.model_year, v.seats, v.fuel,"
		" v.owner_daily_amount, v.status,"
		" o.name AS o_name, o.nic AS o_nic, o.phone AS o_phone, o.address AS o_address, o.bank_account AS o_bank"
		" FROM vehicles v JOIN owners o ON o.id = v.owner_id";
	}

	static Vehicle^ ReadVehicle(MySqlDataReader^ r)
	{
		VehicleType type = safe_cast<VehicleType>(Enum::Parse(VehicleType::typeid, Str(r, "vehicle_type")));
		Vehicle^ v = Vehicle::Create(type);
		v->Id = Int(r, "id");
		v->PlateNumber = Str(r, "plate_number");
		v->Brand = Str(r, "brand");
		v->Model = Str(r, "model");
		v->Year = Int(r, "model_year");
		v->Seats = Int(r, "seats");
		v->Fuel = Str(r, "fuel");
		v->OwnerDailyAmount = Dec(r, "owner_daily_amount");
		v->Status = safe_cast<VehicleStatus>(Enum::Parse(VehicleStatus::typeid, Str(r, "status")));

		VehicleRentalSystem::Owner^ o = gcnew VehicleRentalSystem::Owner();
		o->Name = Str(r, "o_name");
		o->Nic = Str(r, "o_nic");
		o->Phone = Str(r, "o_phone");
		o->Address = Str(r, "o_address");
		o->BankAccount = Str(r, "o_bank");
		v->OwnerInfo = o;
		return v;
	}

	List<Vehicle^>^ VehicleRepository::Query(String^ where, int id)
	{
		List<Vehicle^>^ list = gcnew List<Vehicle^>();
		MySqlConnection^ c = Db::Open();
		try
		{
			MySqlCommand^ cmd = Db::Command(c, VehicleSelect() + where + " ORDER BY v.id");
			if (id >= 0) Db::Param(cmd, "@id", id);
			MySqlDataReader^ r = cmd->ExecuteReader();
			try { while (r->Read()) list->Add(ReadVehicle(r)); }
			finally { delete r; }
		}
		finally { delete c; }
		return list;
	}

	void VehicleRepository::Add(Vehicle^ v)
	{
		MySqlConnection^ c = Db::Open();
		try
		{
			int ownerId = SaveOwner(c, v->OwnerInfo);

			MySqlCommand^ cmd = Db::Command(c,
				"INSERT INTO vehicles (plate_number, vehicle_type, brand, model, model_year, seats, fuel,"
				" owner_daily_amount, status, owner_id)"
				" VALUES (@plate, @type, @brand, @model, @year, @seats, @fuel, @amount, @status, @owner)");
			Db::Param(cmd, "@plate", v->PlateNumber);
			Db::Param(cmd, "@type", v->Type.ToString());
			Db::Param(cmd, "@brand", v->Brand);
			Db::Param(cmd, "@model", v->Model);
			Db::Param(cmd, "@year", v->Year);
			Db::Param(cmd, "@seats", v->Seats);
			Db::Param(cmd, "@fuel", v->Fuel);
			Db::Param(cmd, "@amount", v->OwnerDailyAmount);
			Db::Param(cmd, "@status", v->Status.ToString());
			Db::Param(cmd, "@owner", ownerId);
			cmd->ExecuteNonQuery();
			v->Id = Convert::ToInt32(cmd->LastInsertedId);
		}
		finally { delete c; }
	}

	void VehicleRepository::Update(Vehicle^ v)
	{
		MySqlConnection^ c = Db::Open();
		try
		{
			int ownerId = SaveOwner(c, v->OwnerInfo);

			MySqlCommand^ cmd = Db::Command(c,
				"UPDATE vehicles SET plate_number=@plate, vehicle_type=@type, brand=@brand, model=@model,"
				" model_year=@year, seats=@seats, fuel=@fuel, owner_daily_amount=@amount, status=@status,"
				" owner_id=@owner WHERE id=@id");
			Db::Param(cmd, "@plate", v->PlateNumber);
			Db::Param(cmd, "@type", v->Type.ToString());
			Db::Param(cmd, "@brand", v->Brand);
			Db::Param(cmd, "@model", v->Model);
			Db::Param(cmd, "@year", v->Year);
			Db::Param(cmd, "@seats", v->Seats);
			Db::Param(cmd, "@fuel", v->Fuel);
			Db::Param(cmd, "@amount", v->OwnerDailyAmount);
			Db::Param(cmd, "@status", v->Status.ToString());
			Db::Param(cmd, "@owner", ownerId);
			Db::Param(cmd, "@id", v->Id);
			cmd->ExecuteNonQuery();
		}
		finally { delete c; }
	}

	void VehicleRepository::Remove(int id)
	{
		MySqlConnection^ c = Db::Open();
		try
		{
			MySqlCommand^ cmd = Db::Command(c, "DELETE FROM vehicles WHERE id=@id");
			Db::Param(cmd, "@id", id);
			cmd->ExecuteNonQuery();
		}
		finally { delete c; }
	}

	Vehicle^ VehicleRepository::GetById(int id)
	{
		List<Vehicle^>^ list = Query(" WHERE v.id = @id", id);
		return list->Count > 0 ? list[0] : nullptr;
	}

	List<Vehicle^>^ VehicleRepository::GetAll()
	{
		return Query("", -1);
	}

	// ---------------------------------------------------------------- drivers

	static String^ DriverSelect()
	{
		return
		"SELECT id, name, nic, phone, address, licence_number, licence_expiry, daily_charge, is_busy FROM drivers";
	}

	static Driver^ ReadDriver(MySqlDataReader^ r)
	{
		Driver^ d = gcnew Driver();
		d->Id = Int(r, "id");
		d->Name = Str(r, "name");
		d->Nic = Str(r, "nic");
		d->Phone = Str(r, "phone");
		d->Address = Str(r, "address");
		d->LicenceNumber = Str(r, "licence_number");
		d->LicenceExpiry = Date(r, "licence_expiry");
		d->DailyCharge = Dec(r, "daily_charge");
		d->IsBusy = Convert::ToBoolean(r["is_busy"]);
		return d;
	}

	List<Driver^>^ DriverRepository::Query(String^ where, int id)
	{
		List<Driver^>^ list = gcnew List<Driver^>();
		MySqlConnection^ c = Db::Open();
		try
		{
			MySqlCommand^ cmd = Db::Command(c, DriverSelect() + where + " ORDER BY id");
			if (id >= 0) Db::Param(cmd, "@id", id);
			MySqlDataReader^ r = cmd->ExecuteReader();
			try { while (r->Read()) list->Add(ReadDriver(r)); }
			finally { delete r; }
		}
		finally { delete c; }
		return list;
	}

	void DriverRepository::Add(Driver^ d)
	{
		MySqlConnection^ c = Db::Open();
		try
		{
			MySqlCommand^ cmd = Db::Command(c,
				"INSERT INTO drivers (name, nic, phone, address, licence_number, licence_expiry, daily_charge, is_busy)"
				" VALUES (@name, @nic, @phone, @address, @licence, @expiry, @charge, @busy)");
			Db::Param(cmd, "@name", d->Name);
			Db::Param(cmd, "@nic", d->Nic);
			Db::Param(cmd, "@phone", d->Phone);
			Db::Param(cmd, "@address", d->Address);
			Db::Param(cmd, "@licence", d->LicenceNumber);
			Db::Param(cmd, "@expiry", d->LicenceExpiry.Date);
			Db::Param(cmd, "@charge", d->DailyCharge);
			Db::Param(cmd, "@busy", d->IsBusy);
			cmd->ExecuteNonQuery();
			d->Id = Convert::ToInt32(cmd->LastInsertedId);
		}
		finally { delete c; }
	}

	void DriverRepository::Update(Driver^ d)
	{
		MySqlConnection^ c = Db::Open();
		try
		{
			MySqlCommand^ cmd = Db::Command(c,
				"UPDATE drivers SET name=@name, nic=@nic, phone=@phone, address=@address,"
				" licence_number=@licence, licence_expiry=@expiry, daily_charge=@charge, is_busy=@busy WHERE id=@id");
			Db::Param(cmd, "@name", d->Name);
			Db::Param(cmd, "@nic", d->Nic);
			Db::Param(cmd, "@phone", d->Phone);
			Db::Param(cmd, "@address", d->Address);
			Db::Param(cmd, "@licence", d->LicenceNumber);
			Db::Param(cmd, "@expiry", d->LicenceExpiry.Date);
			Db::Param(cmd, "@charge", d->DailyCharge);
			Db::Param(cmd, "@busy", d->IsBusy);
			Db::Param(cmd, "@id", d->Id);
			cmd->ExecuteNonQuery();
		}
		finally { delete c; }
	}

	void DriverRepository::Remove(int id)
	{
		MySqlConnection^ c = Db::Open();
		try
		{
			MySqlCommand^ cmd = Db::Command(c, "DELETE FROM drivers WHERE id=@id");
			Db::Param(cmd, "@id", id);
			cmd->ExecuteNonQuery();
		}
		finally { delete c; }
	}

	Driver^ DriverRepository::GetById(int id)
	{
		List<Driver^>^ list = Query(" WHERE id = @id", id);
		return list->Count > 0 ? list[0] : nullptr;
	}

	List<Driver^>^ DriverRepository::GetAll()
	{
		return Query("", -1);
	}

	// ---------------------------------------------------------------- bookings

	static String^ BookingSelect()
	{
		return
		"SELECT b.id, b.vehicle_id, b.driver_id, b.from_date, b.to_date, b.days, b.vehicle_daily_rate,"
		" b.driver_daily_charge, b.vehicle_cost, b.driver_cost, b.advance, b.status, b.created_on,"
		" c.name AS c_name, c.nic AS c_nic, c.phone AS c_phone, c.address AS c_address,"
		" v.plate_number, v.brand, v.model, d.name AS d_name"
		" FROM bookings b"
		" JOIN customers c ON c.id = b.customer_id"
		" JOIN vehicles v ON v.id = b.vehicle_id"
		" LEFT JOIN drivers d ON d.id = b.driver_id";
	}

	static Booking^ ReadBooking(MySqlDataReader^ r)
	{
		Booking^ b = gcnew Booking();
		b->Id = Int(r, "id");

		Customer^ cu = gcnew Customer();
		cu->Name = Str(r, "c_name");
		cu->Nic = Str(r, "c_nic");
		cu->Phone = Str(r, "c_phone");
		cu->Address = Str(r, "c_address");
		b->CustomerInfo = cu;

		b->VehicleId = Int(r, "vehicle_id");
		b->VehicleName = Str(r, "plate_number") + " - " + Str(r, "brand") + " " + Str(r, "model");

		if (r->IsDBNull(r->GetOrdinal("driver_id")))
		{
			b->DriverId = 0;
			b->DriverName = "";
		}
		else
		{
			b->DriverId = Int(r, "driver_id");
			b->DriverName = Str(r, "d_name");
		}

		b->FromDate = Date(r, "from_date");
		b->ToDate = Date(r, "to_date");
		b->Days = Int(r, "days");
		b->VehicleDailyRate = Dec(r, "vehicle_daily_rate");
		b->DriverDailyCharge = Dec(r, "driver_daily_charge");
		b->VehicleCost = Dec(r, "vehicle_cost");
		b->DriverCost = Dec(r, "driver_cost");
		b->Advance = Dec(r, "advance");
		b->Status = safe_cast<BookingStatus>(Enum::Parse(BookingStatus::typeid, Str(r, "status")));
		b->CreatedOn = Date(r, "created_on");
		return b;
	}

	List<Booking^>^ BookingRepository::Query(String^ where, int id)
	{
		List<Booking^>^ list = gcnew List<Booking^>();
		MySqlConnection^ c = Db::Open();
		try
		{
			MySqlCommand^ cmd = Db::Command(c, BookingSelect() + where + " ORDER BY b.id");
			if (id >= 0) Db::Param(cmd, "@id", id);
			MySqlDataReader^ r = cmd->ExecuteReader();
			try { while (r->Read()) list->Add(ReadBooking(r)); }
			finally { delete r; }
		}
		finally { delete c; }
		return list;
	}

	void BookingRepository::Add(Booking^ b)
	{
		MySqlConnection^ c = Db::Open();
		try
		{
			int customerId = SaveCustomer(c, b->CustomerInfo);

			MySqlCommand^ cmd = Db::Command(c,
				"INSERT INTO bookings (customer_id, vehicle_id, driver_id, from_date, to_date, days,"
				" vehicle_daily_rate, driver_daily_charge, vehicle_cost, driver_cost, advance, status, created_on)"
				" VALUES (@customer, @vehicle, @driver, @from, @to, @days, @vrate, @drate, @vcost, @dcost,"
				" @advance, @status, @created)");
			Db::Param(cmd, "@customer", customerId);
			Db::Param(cmd, "@vehicle", b->VehicleId);
			if (b->DriverId > 0) Db::Param(cmd, "@driver", b->DriverId);
			else Db::Param(cmd, "@driver", DBNull::Value);
			Db::Param(cmd, "@from", b->FromDate.Date);
			Db::Param(cmd, "@to", b->ToDate.Date);
			Db::Param(cmd, "@days", b->Days);
			Db::Param(cmd, "@vrate", b->VehicleDailyRate);
			Db::Param(cmd, "@drate", b->DriverDailyCharge);
			Db::Param(cmd, "@vcost", b->VehicleCost);
			Db::Param(cmd, "@dcost", b->DriverCost);
			Db::Param(cmd, "@advance", b->Advance);
			Db::Param(cmd, "@status", b->Status.ToString());
			Db::Param(cmd, "@created", b->CreatedOn);
			cmd->ExecuteNonQuery();
			b->Id = Convert::ToInt32(cmd->LastInsertedId);
		}
		finally { delete c; }
	}

	void BookingRepository::Update(Booking^ b)
	{
		MySqlConnection^ c = Db::Open();
		try
		{
			MySqlCommand^ cmd = Db::Command(c, "UPDATE bookings SET status=@status, advance=@advance WHERE id=@id");
			Db::Param(cmd, "@status", b->Status.ToString());
			Db::Param(cmd, "@advance", b->Advance);
			Db::Param(cmd, "@id", b->Id);
			cmd->ExecuteNonQuery();
		}
		finally { delete c; }
	}

	void BookingRepository::Remove(int id)
	{
		MySqlConnection^ c = Db::Open();
		try
		{
			MySqlCommand^ cmd = Db::Command(c, "DELETE FROM bookings WHERE id=@id");
			Db::Param(cmd, "@id", id);
			cmd->ExecuteNonQuery();
		}
		finally { delete c; }
	}

	Booking^ BookingRepository::GetById(int id)
	{
		List<Booking^>^ list = Query(" WHERE b.id = @id", id);
		return list->Count > 0 ? list[0] : nullptr;
	}

	List<Booking^>^ BookingRepository::GetAll()
	{
		return Query("", -1);
	}
}

