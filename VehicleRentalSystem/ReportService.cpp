#include "ReportService.h"
#include "Db.h"

namespace VehicleRentalSystem
{
	DashboardSummary^ ReportService::GetSummary()
	{
		DashboardSummary^ s = gcnew DashboardSummary();

		for each (Vehicle^ v in Db::Vehicles->GetAll())
		{
			s->TotalVehicles = s->TotalVehicles + 1;
			if (v->Status == VehicleStatus::Available) s->AvailableVehicles = s->AvailableVehicles + 1;
			else s->RentedVehicles = s->RentedVehicles + 1;
		}

		for each (Booking^ b in Db::Bookings->GetAll())
		{
			s->TotalIncome = s->TotalIncome + b->VehicleCost;
			s->OwnerPayable = s->OwnerPayable + b->OwnerShare;
			s->CompanyProfit = s->CompanyProfit + b->CompanyCommission;
		}
		return s;
	}

	List<VehicleIncomeRow^>^ ReportService::GetVehicleIncome()
	{
		List<Booking^>^ bookings = Db::Bookings->GetAll();
		List<VehicleIncomeRow^>^ rows = gcnew List<VehicleIncomeRow^>();

		for each (Vehicle^ v in Db::Vehicles->GetAll())
		{
			VehicleIncomeRow^ row = gcnew VehicleIncomeRow();
			row->Vehicle = v->ToString();
			row->Owner = v->OwnerInfo->Name;

			for each (Booking^ b in bookings)
			{
				if (b->VehicleId != v->Id) continue;
				row->Rentals = row->Rentals + 1;
				row->Income = row->Income + b->VehicleCost;
				row->OwnerPayable = row->OwnerPayable + b->OwnerShare;
				row->CompanyProfit = row->CompanyProfit + b->CompanyCommission;
			}
			rows->Add(row);
		}
		return rows;
	}

	List<Booking^>^ ReportService::GetActiveBookings()
	{
		List<Booking^>^ result = gcnew List<Booking^>();
		for each (Booking^ b in Db::Bookings->GetAll())
		{
			if (b->Status == BookingStatus::Active) result->Add(b);
		}
		return result;
	}
}
