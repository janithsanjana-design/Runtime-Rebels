#pragma once
#include "IRepository.h"
#include "Vehicle.h"
#include "Booking.h"

namespace VehicleRentalSystem
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace MySql::Data::MySqlClient;

	/// vehicles + owners tables
	public ref class VehicleRepository : IRepository<Vehicle^>
	{
	private:
		List<Vehicle^>^ Query(String^ where, int id);

	public:
		virtual void Add(Vehicle^ item);
		virtual void Update(Vehicle^ item);
		virtual void Remove(int id);
		virtual Vehicle^ GetById(int id);
		virtual List<Vehicle^>^ GetAll();
	};

	/// drivers table
	public ref class DriverRepository : IRepository<Driver^>
	{
	private:
		List<Driver^>^ Query(String^ where, int id);

	public:
		virtual void Add(Driver^ item);
		virtual void Update(Driver^ item);
		virtual void Remove(int id);
		virtual Driver^ GetById(int id);
		virtual List<Driver^>^ GetAll();
	};

	/// bookings + customers tables
	public ref class BookingRepository : IRepository<Booking^>
	{
	private:
		List<Booking^>^ Query(String^ where, int id);

	public:
		virtual void Add(Booking^ item);
		virtual void Update(Booking^ item);
		virtual void Remove(int id);
		virtual Booking^ GetById(int id);
		virtual List<Booking^>^ GetAll();
	};
}
