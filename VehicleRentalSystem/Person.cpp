#include "Person.h"

namespace VehicleRentalSystem
{
	using namespace System::Text::RegularExpressions;

	// ---------------- Person ----------------

	Person::Person()
	{
		_name = "";
		_nic = "";
		_phone = "";
		_address = "";
	}

	String^ Person::Required(String^ value, String^ field)
	{
		if (String::IsNullOrWhiteSpace(value))
			throw gcnew ArgumentException(field + " is required.");
		return value->Trim();
	}

	String^ Person::Name::get() { return _name; }
	void Person::Name::set(String^ value) { _name = Required(value, "Name"); }

	String^ Person::Nic::get() { return _nic; }
	void Person::Nic::set(String^ value)
	{
		String^ v = Required(value, "NIC")->ToUpper();
		if (!Regex::IsMatch(v, "^(\\d{9}[VX]|\\d{12})$"))
			throw gcnew ArgumentException("NIC must be 9 digits followed by V (e.g. 901234567V) or 12 digits.");
		_nic = v;
	}

	String^ Person::Phone::get() { return _phone; }
	void Person::Phone::set(String^ value)
	{
		String^ v = Required(value, "Phone");
		if (!Regex::IsMatch(v, "^\\d{10}$"))
			throw gcnew ArgumentException("Phone number must be 10 digits (e.g. 0771234567).");
		_phone = v;
	}

	String^ Person::Address::get() { return _address; }
	void Person::Address::set(String^ value) { _address = Required(value, "Address"); }

	// ---------------- Owner ----------------

	Owner::Owner() { _bankAccount = ""; }

	String^ Owner::BankAccount::get() { return _bankAccount; }
	void Owner::BankAccount::set(String^ value) { _bankAccount = Required(value, "Bank account"); }

	// ---------------- Driver ----------------

	Driver::Driver()
	{
		_id = 0;
		_licenceNumber = "";
		_dailyCharge = Decimal::Zero;
	}

	String^ Driver::LicenceNumber::get() { return _licenceNumber; }
	void Driver::LicenceNumber::set(String^ value) { _licenceNumber = Required(value, "Licence number")->ToUpper(); }

	Decimal Driver::DailyCharge::get() { return _dailyCharge; }
	void Driver::DailyCharge::set(Decimal value)
	{
		if (value <= Decimal::Zero)
			throw gcnew ArgumentException("Daily charge must be greater than zero.");
		_dailyCharge = value;
	}
}
