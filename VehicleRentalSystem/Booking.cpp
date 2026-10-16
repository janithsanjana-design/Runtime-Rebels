#include "Booking.h"
#include "CommissionCalculator.h"

namespace VehicleRentalSystem
{
	Booking::Booking()
	{
		_id = 0;
		VehicleName = "";
		DriverName = "";
	}

	Decimal Booking::Total::get() { return VehicleCost + DriverCost; }

	Decimal Booking::Balance::get() { return Total - Advance; }

	Decimal Booking::CompanyCommission::get() { return CommissionCalculator::Commission(VehicleCost); }

	Decimal Booking::OwnerShare::get() { return VehicleCost - CompanyCommission; }
}
