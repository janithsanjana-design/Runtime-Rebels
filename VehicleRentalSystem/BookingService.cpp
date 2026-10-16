#include "BookingService.h"
#include "Db.h"
#include "VehicleNotAvailableException.h"

namespace VehicleRentalSystem
{
	int BookingService::CountDays(DateTime fromDate, DateTime toDate)
	{
		TimeSpan span = toDate.Date - fromDate.Date;
		return span.Days + 1;
	}

	Decimal BookingService::MinAdvance(Decimal total)
	{
		return Math::Round(total * MinAdvancePercent, 2);
	}

	bool BookingService::IsVehicleFree(Vehicle^ vehicle, DateTime fromDate, DateTime toDate)
	{
		if (vehicle->Status != VehicleStatus::Available) return false;

		for each (Booking^ b in Db::Bookings->GetAll())
		{
			if (b->VehicleId == vehicle->Id &&
				b->Status == BookingStatus::Active &&
				fromDate.Date <= b->ToDate.Date && toDate.Date >= b->FromDate.Date)
			{
				return false;
			}
		}
		return true;
	}

	int BookingService::CompareByRate(Vehicle^ a, Vehicle^ b)
	{
		return Decimal::Compare(a->CustomerDailyRate, b->CustomerDailyRate);
	}

	List<Vehicle^>^ BookingService::GetAvailableVehicles(bool anyType, VehicleType type, int passengers,
		DateTime fromDate, DateTime toDate)
	{
		List<Vehicle^>^ result = gcnew List<Vehicle^>();
		for each (Vehicle^ v in Db::Vehicles->GetAll())
		{
			if ((anyType || v->Type == type) && v->Seats >= passengers && IsVehicleFree(v, fromDate, toDate))
				result->Add(v);
		}
		result->Sort(gcnew Comparison<Vehicle^>(&BookingService::CompareByRate));
		return result;
	}

	List<Driver^>^ BookingService::GetAvailableDrivers(DateTime toDate)
	{
		List<Driver^>^ result = gcnew List<Driver^>();
		for each (Driver^ d in Db::Drivers->GetAll())
		{
			if (!d->IsBusy && d->LicenceExpiry.Date >= toDate.Date)
				result->Add(d);
		}
		return result;
	}

	Booking^ BookingService::CreateBooking(Customer^ customer, Vehicle^ vehicle, Driver^ driver,
		DateTime fromDate, DateTime toDate, Decimal advance, bool allowPastDates)
	{
		if (customer == nullptr) throw gcnew ArgumentException("Customer details are required.");
		if (vehicle == nullptr) throw gcnew ArgumentException("Please select a vehicle.");
		if (toDate.Date < fromDate.Date)
			throw gcnew ArgumentException("The return date must be on or after the pick-up date.");
		if (!allowPastDates && fromDate.Date < DateTime::Today)
			throw gcnew ArgumentException("The pick-up date cannot be in the past.");

		if (!IsVehicleFree(vehicle, fromDate, toDate))
			throw gcnew VehicleNotAvailableException(vehicle->PlateNumber);

		if (driver != nullptr)
		{
			if (driver->IsBusy) throw gcnew ArgumentException("The selected driver is not available.");
			if (driver->LicenceExpiry.Date < toDate.Date)
				throw gcnew ArgumentException("The driver's licence expires before the end of the rental.");
		}

		int days = CountDays(fromDate, toDate);
		Decimal vehicleCost = Decimal(days) * vehicle->CustomerDailyRate;
		Decimal driverCost = driver == nullptr ? Decimal::Zero : Decimal(days) * driver->DailyCharge;
		Decimal total = vehicleCost + driverCost;

		if (advance < MinAdvance(total))
			throw gcnew ArgumentException(String::Format(
				"The advance payment must be at least 25% of the total ({0}).", MinAdvance(total).ToString("N2")));
		if (advance > total)
			throw gcnew ArgumentException("The advance payment cannot be more than the total amount.");

		Booking^ booking = gcnew Booking();
		booking->CustomerInfo = customer;
		booking->VehicleId = vehicle->Id;
		booking->VehicleName = vehicle->ToString();
		booking->DriverId = driver == nullptr ? 0 : driver->Id;
		booking->DriverName = driver == nullptr ? "" : driver->Name;
		booking->FromDate = fromDate.Date;
		booking->ToDate = toDate.Date;
		booking->Days = days;
		booking->VehicleDailyRate = vehicle->CustomerDailyRate;
		booking->DriverDailyCharge = driver == nullptr ? Decimal::Zero : driver->DailyCharge;
		booking->VehicleCost = vehicleCost;
		booking->DriverCost = driverCost;
		booking->Advance = advance;
		booking->Status = BookingStatus::Active;
		booking->CreatedOn = DateTime::Now;

		vehicle->Status = VehicleStatus::Rented;
		if (driver != nullptr) driver->IsBusy = true;

		Db::Bookings->Add(booking);
		Db::Vehicles->Update(vehicle);                    // vehicle is now Rented
		if (driver != nullptr) Db::Drivers->Update(driver);   // driver is now Busy
		return booking;
	}

	void BookingService::CompleteBooking(Booking^ booking)
	{
		booking->Status = BookingStatus::Completed;

		Vehicle^ vehicle = Db::Vehicles->GetById(booking->VehicleId);
		if (vehicle != nullptr)
		{
			vehicle->Status = VehicleStatus::Available;
			Db::Vehicles->Update(vehicle);
		}

		Driver^ driver = (booking->DriverId > 0) ? Db::Drivers->GetById(booking->DriverId) : nullptr;
		if (driver != nullptr)
		{
			driver->IsBusy = false;
			Db::Drivers->Update(driver);
		}

		Db::Bookings->Update(booking);
	}
}
