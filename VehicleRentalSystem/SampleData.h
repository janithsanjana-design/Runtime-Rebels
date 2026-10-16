#pragma once
#include "Vehicle.h"
#include "Booking.h"

namespace VehicleRentalSystem
{
	using namespace System;

	/// A few vehicles, drivers and bookings so the dashboard is not empty on first run.
	public ref class SampleData abstract sealed
	{
	private:
		static void Past(Customer^ c, Vehicle^ v, Driver^ d, int daysAgoFrom, int daysAgoTo);
		static Owner^ NewOwner(String^ name, String^ nic, String^ phone, String^ address, String^ bank);
		static Customer^ NewCustomer(String^ name, String^ nic, String^ phone, String^ address);
		static Driver^ NewDriver(String^ name, String^ nic, String^ phone, String^ address, String^ licence, int charge);
		static Vehicle^ NewVehicle(VehicleType type, String^ plate, String^ brand, String^ model, int year,
			int seats, String^ fuel, int ownerAmount, Owner^ owner);

	public:
		static void Seed();
	};
}
