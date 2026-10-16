#pragma once
#include "Vehicle.h"
#include "Booking.h"

namespace VehicleRentalSystem
{
	using namespace System;
	using namespace System::Collections::Generic;

	/// All booking rules (dates, double booking, advance payment) are in this one class.
	public ref class BookingService abstract sealed
	{
	private:
		static int CompareByRate(Vehicle^ a, Vehicle^ b);

	public:
		/// Customers must pay at least this part (25%) of the total as advance.
		static property Decimal MinAdvancePercent { Decimal get() { return Decimal(25, 0, 0, false, 2); } }

		/// Both the pick-up day and the return day count as rental days.
		static int CountDays(DateTime fromDate, DateTime toDate);

		static Decimal MinAdvance(Decimal total);

		/// True when the vehicle is free and has no active booking overlapping these dates.
		static bool IsVehicleFree(Vehicle^ vehicle, DateTime fromDate, DateTime toDate);

		/// Available vehicles that match the customer's requirement (anyType = true ignores the type).
		static List<Vehicle^>^ GetAvailableVehicles(bool anyType, VehicleType type, int passengers, DateTime fromDate, DateTime toDate);

		/// Drivers who are free and whose licence is still valid on the last rental day.
		static List<Driver^>^ GetAvailableDrivers(DateTime toDate);

		static Booking^ CreateBooking(Customer^ customer, Vehicle^ vehicle, Driver^ driver,
			DateTime fromDate, DateTime toDate, Decimal advance, bool allowPastDates);

		/// Customer returns the vehicle: booking completed, vehicle and driver free again.
		static void CompleteBooking(Booking^ booking);
	};
}
