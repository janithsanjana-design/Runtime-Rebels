#pragma once
#include "Vehicle.h"
#include "Booking.h"
#include "IRepository.h"

namespace VehicleRentalSystem
{
	using namespace System;
	using namespace MySql::Data::MySqlClient;

	/// MySQL connection settings, saved in %AppData%\VehicleRentalSystem\dbconfig.ini
	public ref class DbConfig
	{
	public:
		String^ Server;
		int Port;
		String^ Database;
		String^ User;
		String^ Password;

		DbConfig();

		static String^ FilePath();
		static DbConfig^ Load();
		void Save();

		/// withDatabase = false connects to the server only (used to create the database).
		String^ ConnectionString(bool withDatabase);
	};

	/// Connects to MySQL, creates the database and tables on first run,
	/// and exposes one repository per table.
	public ref class Db abstract sealed
	{
	private:
		static DbConfig^ _config;
		static IRepository<Vehicle^>^ _vehicles;
		static IRepository<Driver^>^ _drivers;
		static IRepository<Booking^>^ _bookings;

		static void CreateTables(MySqlConnection^ c);

	public:
		static property IRepository<Vehicle^>^ Vehicles { IRepository<Vehicle^>^ get() { return _vehicles; } }
		static property IRepository<Driver^>^ Drivers { IRepository<Driver^>^ get() { return _drivers; } }
		static property IRepository<Booking^>^ Bookings { IRepository<Booking^>^ get() { return _bookings; } }

		/// Throws an exception with a readable message when MySQL cannot be reached.
		static void Initialize();

		/// Opens a new connection to the application database.
		static MySqlConnection^ Open();

		// small helpers used by the repositories
		static MySqlCommand^ Command(MySqlConnection^ c, String^ sql);
		static void Param(MySqlCommand^ cmd, String^ name, Object^ value);
		static void Execute(MySqlConnection^ c, String^ sql);
	};
}
