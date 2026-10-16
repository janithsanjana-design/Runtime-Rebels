#include "Vehicle.h"
#include "CommissionCalculator.h"

namespace VehicleRentalSystem
{
	Vehicle::Vehicle()
	{
		_id = 0;
		_plate = "";
		_brand = "";
		_model = "";
		_fuel = "";
		_year = DateTime::Now.Year;
		_seats = 1;
		_ownerDailyAmount = Decimal::Zero;
		Status = VehicleStatus::Available;
	}

	String^ Vehicle::PlateNumber::get() { return _plate; }
	void Vehicle::PlateNumber::set(String^ value)
	{
		if (String::IsNullOrWhiteSpace(value)) throw gcnew ArgumentException("Plate number is required.");
		_plate = value->Trim()->ToUpper();
	}

	String^ Vehicle::Brand::get() { return _brand; }
	void Vehicle::Brand::set(String^ value)
	{
		if (String::IsNullOrWhiteSpace(value)) throw gcnew ArgumentException("Brand is required.");
		_brand = value->Trim();
	}

	String^ Vehicle::Model::get() { return _model; }
	void Vehicle::Model::set(String^ value)
	{
		if (String::IsNullOrWhiteSpace(value)) throw gcnew ArgumentException("Model is required.");
		_model = value->Trim();
	}

	String^ Vehicle::Fuel::get() { return _fuel; }
	void Vehicle::Fuel::set(String^ value)
	{
		if (String::IsNullOrWhiteSpace(value)) throw gcnew ArgumentException("Fuel type is required.");
		_fuel = value->Trim();
	}

	int Vehicle::Year::get() { return _year; }
	void Vehicle::Year::set(int value)
	{
		int maxYear = DateTime::Now.Year + 1;
		if (value < 1980 || value > maxYear)
			throw gcnew ArgumentException("Year must be between 1980 and " + Convert::ToString(maxYear) + ".");
		_year = value;
	}

	int Vehicle::Seats::get() { return _seats; }
	void Vehicle::Seats::set(int value)
	{
		if (value < 1 || value > 60) throw gcnew ArgumentException("Seats must be between 1 and 60.");
		_seats = value;
	}

	Decimal Vehicle::OwnerDailyAmount::get() { return _ownerDailyAmount; }
	void Vehicle::OwnerDailyAmount::set(Decimal value)
	{
		if (value <= Decimal::Zero)
			throw gcnew ArgumentException("The owner's daily amount must be greater than zero.");
		_ownerDailyAmount = value;
	}

	Decimal Vehicle::CustomerDailyRate::get()
	{
		return CommissionCalculator::CustomerPrice(_ownerDailyAmount);
	}

	Vehicle^ Vehicle::Create(VehicleType type)
	{
		switch (type)
		{
		case VehicleType::Car: return gcnew Car();
		case VehicleType::Van: return gcnew Van();
		case VehicleType::SUV: return gcnew Suv();
		case VehicleType::Bike: return gcnew Bike();
		default: return gcnew Bus();
		}
	}

	String^ Vehicle::ToString()
	{
		return PlateNumber + " - " + Brand + " " + Model;
	}

	String^ Car::GetDetails() { return "Car, " + Convert::ToString(Seats) + " seats, " + Fuel; }
	String^ Van::GetDetails() { return "Van for groups, " + Convert::ToString(Seats) + " seats, " + Fuel; }
	String^ Suv::GetDetails() { return "SUV, " + Convert::ToString(Seats) + " seats, " + Fuel + ", good for rough roads"; }
	String^ Bike::GetDetails() { return "Motorbike, " + Fuel + ", helmet included"; }
	String^ Bus::GetDetails() { return "Bus, " + Convert::ToString(Seats) + " seats, " + Fuel; }
}
