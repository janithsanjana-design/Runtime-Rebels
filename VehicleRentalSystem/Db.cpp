#include "Db.h"
#include "Repositories.h"
#include "SampleData.h"

namespace VehicleRentalSystem
{
	using namespace System::IO;
	using namespace System::Text::RegularExpressions;

	// ------------------------------------------------------------ DbConfig

	DbConfig::DbConfig()
	{
		Server = "localhost";
		Port = 3306;
		Database = "vehicle_rental";
		User = "root";
		Password = "";
	}

	String^ DbConfig::FilePath()
	{
		String^ folder = Path::Combine(
			Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData), "VehicleRentalSystem");
		Directory::CreateDirectory(folder);
		return Path::Combine(folder, "dbconfig.ini");
	}

	DbConfig^ DbConfig::Load()
	{
		DbConfig^ cfg = gcnew DbConfig();
		String^ path = FilePath();
		if (!File::Exists(path)) return cfg;

		for each (String^ line in File::ReadAllLines(path))
		{
			int eq = line->IndexOf('=');
			if (eq <= 0) continue;
			String^ key = line->Substring(0, eq)->Trim();
			String^ value = line->Substring(eq + 1)->Trim();

			if (key == "Server") cfg->Server = value;
			else if (key == "Port") { int p; if (Int32::TryParse(value, p)) cfg->Port = p; }
			else if (key == "Database") cfg->Database = value;
			else if (key == "User") cfg->User = value;
			else if (key == "Password") cfg->Password = value;
		}
		return cfg;
	}

	void DbConfig::Save()
	{
		array<String^>^ lines = gcnew array<String^> {
			"Server=" + Server,
			"Port=" + Convert::ToString(Port),
			"Database=" + Database,
			"User=" + User,
			"Password=" + Password };
		File::WriteAllLines(FilePath(), lines);
	}

	String^ DbConfig::ConnectionString(bool withDatabase)
	{
		MySqlConnectionStringBuilder^ b = gcnew MySqlConnectionStringBuilder();
		b->Server = Server;
		b->Port = (unsigned int)Port;
		b->UserID = User;
		b->Password = Password;
		b->CharacterSet = "utf8mb4";
		b->AllowPublicKeyRetrieval = true;
		b->ConnectionTimeout = 8;
		if (withDatabase) b->Database = Database;
		return b->ConnectionString;
	}

	// ------------------------------------------------------------ Db

	MySqlCommand^ Db::Command(MySqlConnection^ c, String^ sql)
	{
		return gcnew MySqlCommand(sql, c);
	}

	void Db::Param(MySqlCommand^ cmd, String^ name, Object^ value)
	{
		cmd->Parameters->AddWithValue(name, value);
	}

	void Db::Execute(MySqlConnection^ c, String^ sql)
	{
		MySqlCommand^ cmd = Command(c, sql);
		cmd->ExecuteNonQuery();
	}

	MySqlConnection^ Db::Open()
	{
		MySqlConnection^ c = gcnew MySqlConnection(_config->ConnectionString(true));
		c->Open();
		return c;
	}

	void Db::Initialize()
	{
		_config = DbConfig::Load();

		// The database name is used inside SQL text, so only simple names are allowed.
		if (!Regex::IsMatch(_config->Database, "^[A-Za-z0-9_]{1,40}$"))
			throw gcnew ArgumentException("Database name may only contain letters, digits and underscore.");

		bool needSeed = false;

		// 1. connect to the server and create the database + tables if they are missing
		MySqlConnection^ server = gcnew MySqlConnection(_config->ConnectionString(false));
		try
		{
			server->Open();
			Execute(server, "CREATE DATABASE IF NOT EXISTS `" + _config->Database + "` CHARACTER SET utf8mb4");
			server->ChangeDatabase(_config->Database);
			CreateTables(server);

			MySqlCommand^ check = Command(server, "SELECT COUNT(*) FROM app_meta WHERE k = 'seeded'");
			needSeed = Convert::ToInt32(check->ExecuteScalar()) == 0;
		}
		finally
		{
			delete server;
		}

		// 2. repositories
		_vehicles = gcnew VehicleRepository();
		_drivers = gcnew DriverRepository();
		_bookings = gcnew BookingRepository();

		// 3. sample data on the very first run
		if (needSeed)
		{
			SampleData::Seed();
			MySqlConnection^ c = Open();
			try { Execute(c, "INSERT INTO app_meta (k, v) VALUES ('seeded', 'yes')"); }
			finally { delete c; }
		}

		// connection worked: remember the settings
		_config->Save();
	}

	void Db::CreateTables(MySqlConnection^ c)
	{
		Execute(c,
			"CREATE TABLE IF NOT EXISTS owners ("
			" id INT AUTO_INCREMENT PRIMARY KEY,"
			" name VARCHAR(100) NOT NULL,"
			" nic VARCHAR(12) NOT NULL UNIQUE,"
			" phone VARCHAR(10) NOT NULL,"
			" address VARCHAR(200) NOT NULL,"
			" bank_account VARCHAR(60) NOT NULL)");

		Execute(c,
			"CREATE TABLE IF NOT EXISTS customers ("
			" id INT AUTO_INCREMENT PRIMARY KEY,"
			" name VARCHAR(100) NOT NULL,"
			" nic VARCHAR(12) NOT NULL UNIQUE,"
			" phone VARCHAR(10) NOT NULL,"
			" address VARCHAR(200) NOT NULL)");

		Execute(c,
			"CREATE TABLE IF NOT EXISTS vehicles ("
			" id INT AUTO_INCREMENT PRIMARY KEY,"
			" plate_number VARCHAR(20) NOT NULL UNIQUE,"
			" vehicle_type VARCHAR(10) NOT NULL,"
			" brand VARCHAR(50) NOT NULL,"
			" model VARCHAR(50) NOT NULL,"
			" model_year INT NOT NULL,"
			" seats INT NOT NULL,"
			" fuel VARCHAR(20) NOT NULL,"
			" owner_daily_amount DECIMAL(12,2) NOT NULL,"
			" status VARCHAR(10) NOT NULL,"
			" owner_id INT NOT NULL,"
			" FOREIGN KEY (owner_id) REFERENCES owners(id))");

		Execute(c,
			"CREATE TABLE IF NOT EXISTS drivers ("
			" id INT AUTO_INCREMENT PRIMARY KEY,"
			" name VARCHAR(100) NOT NULL,"
			" nic VARCHAR(12) NOT NULL UNIQUE,"
			" phone VARCHAR(10) NOT NULL,"
			" address VARCHAR(200) NOT NULL,"
			" licence_number VARCHAR(30) NOT NULL UNIQUE,"
			" licence_expiry DATE NOT NULL,"
			" daily_charge DECIMAL(12,2) NOT NULL,"
			" is_busy TINYINT(1) NOT NULL DEFAULT 0)");

		Execute(c,
			"CREATE TABLE IF NOT EXISTS bookings ("
			" id INT AUTO_INCREMENT PRIMARY KEY,"
			" customer_id INT NOT NULL,"
			" vehicle_id INT NOT NULL,"
			" driver_id INT NULL,"
			" from_date DATE NOT NULL,"
			" to_date DATE NOT NULL,"
			" days INT NOT NULL,"
			" vehicle_daily_rate DECIMAL(12,2) NOT NULL,"
			" driver_daily_charge DECIMAL(12,2) NOT NULL,"
			" vehicle_cost DECIMAL(12,2) NOT NULL,"
			" driver_cost DECIMAL(12,2) NOT NULL,"
			" advance DECIMAL(12,2) NOT NULL,"
			" status VARCHAR(12) NOT NULL,"
			" created_on DATETIME NOT NULL,"
			" FOREIGN KEY (customer_id) REFERENCES customers(id),"
			" FOREIGN KEY (vehicle_id) REFERENCES vehicles(id),"
			" FOREIGN KEY (driver_id) REFERENCES drivers(id))");

		Execute(c,
			"CREATE TABLE IF NOT EXISTS app_meta ("
			" k VARCHAR(40) PRIMARY KEY,"
			" v VARCHAR(100) NOT NULL)");
	}
}
