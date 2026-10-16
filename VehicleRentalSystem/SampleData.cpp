#include "SampleData.h"
#include "Db.h"
#include "BookingService.h"

namespace VehicleRentalSystem
{
	void SampleData::Seed()
	{
		Owner^ nimal = NewOwner("Nimal Perera", "901234567V", "0771234567", "12 Galle Road, Colombo", "BOC 1234567890");
		Owner^ kamal = NewOwner("Kamal Silva", "851234567V", "0712223344", "45 Kandy Road, Kelaniya", "Sampath 9876543210");

		Vehicle^ axio = NewVehicle(VehicleType::Car, "CAB-1234", "Toyota", "Axio", 2018, 4, "Petrol", 9000, nimal);
		Vehicle^ kdh = NewVehicle(VehicleType::Van, "VAN-5566", "Toyota", "KDH", 2017, 12, "Diesel", 14000, kamal);
		Vehicle^ vezel = NewVehicle(VehicleType::SUV, "KB-7788", "Honda", "Vezel", 2019, 5, "Hybrid", 12000, kamal);
		NewVehicle(VehicleType::Bike, "BIK-4321", "Bajaj", "Pulsar", 2020, 2, "Petrol", 2500, nimal);

		Driver^ sunil = NewDriver("Sunil Fernando", "821234567V", "0753334455", "8 Temple Road, Gampaha", "B1234567", 3500);
		NewDriver("Ruwan Silva", "881112223V", "0764445566", "21 Lake Road, Kandy", "B7654321", 3000);

		Customer^ amal = NewCustomer("Amal Jayasena", "881234567V", "0712345678", "5 Park Street, Colombo");
		Customer^ dilani = NewCustomer("Dilani Perera", "199012345678", "0701112233", "17 Beach Road, Negombo");

		Past(amal, axio, nullptr, 10, 7);
		Past(dilani, kdh, sunil, 6, 4);

		// One rental that is still running.
		Customer^ saman = NewCustomer("Saman Kumara", "791234567V", "0723456789", "9 Hill Street, Matara");
		DateTime today = DateTime::Today;
		Decimal total = Decimal(BookingService::CountDays(today, today.AddDays(2))) * vezel->CustomerDailyRate;
		BookingService::CreateBooking(saman, vezel, nullptr, today, today.AddDays(2),
			BookingService::MinAdvance(total), true);
	}

	// A booking that already finished some days ago.
	void SampleData::Past(Customer^ c, Vehicle^ v, Driver^ d, int daysAgoFrom, int daysAgoTo)
	{
		DateTime fromDate = DateTime::Today.AddDays(-daysAgoFrom);
		DateTime toDate = DateTime::Today.AddDays(-daysAgoTo);

		Decimal perDay = v->CustomerDailyRate;
		if (d != nullptr) perDay = perDay + d->DailyCharge;
		Decimal total = Decimal(BookingService::CountDays(fromDate, toDate)) * perDay;

		Booking^ b = BookingService::CreateBooking(c, v, d, fromDate, toDate, total, true);
		BookingService::CompleteBooking(b);
	}

	Owner^ SampleData::NewOwner(String^ name, String^ nic, String^ phone, String^ address, String^ bank)
	{
		Owner^ o = gcnew Owner();
		o->Name = name; o->Nic = nic; o->Phone = phone; o->Address = address; o->BankAccount = bank;
		return o;
	}

	Customer^ SampleData::NewCustomer(String^ name, String^ nic, String^ phone, String^ address)
	{
		Customer^ c = gcnew Customer();
		c->Name = name; c->Nic = nic; c->Phone = phone; c->Address = address;
		return c;
	}

	Driver^ SampleData::NewDriver(String^ name, String^ nic, String^ phone, String^ address, String^ licence, int charge)
	{
		Driver^ d = gcnew Driver();
		d->Name = name; d->Nic = nic; d->Phone = phone; d->Address = address;
		d->LicenceNumber = licence;
		d->LicenceExpiry = DateTime::Today.AddYears(2);
		d->DailyCharge = Decimal(charge);
		Db::Drivers->Add(d);
		return d;
	}

	Vehicle^ SampleData::NewVehicle(VehicleType type, String^ plate, String^ brand, String^ model, int year,
		int seats, String^ fuel, int ownerAmount, Owner^ owner)
	{
		Vehicle^ v = Vehicle::Create(type);
		v->PlateNumber = plate; v->Brand = brand; v->Model = model; v->Year = year;
		v->Seats = seats; v->Fuel = fuel; v->OwnerDailyAmount = Decimal(ownerAmount);
		v->OwnerInfo = owner;
		v->Status = VehicleStatus::Available;
		Db::Vehicles->Add(v);
		return v;
	}
}
