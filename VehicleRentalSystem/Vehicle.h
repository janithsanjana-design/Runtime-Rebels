#pragma once
#include "Enums.h"
#include "IEntity.h"
#include "Person.h"

namespace VehicleRentalSystem
{
	using namespace System;

	/// INHERITANCE + POLYMORPHISM: base class of every vehicle type.
	/// Each subclass overrides Type and GetDetails().
	public ref class Vehicle abstract : IEntity
	{
	private:
		int _id;
		String^ _plate;
		String^ _brand;
		String^ _model;
		String^ _fuel;
		int _year;
		int _seats;
		Decimal _ownerDailyAmount;

	public:
		Vehicle();

		virtual property int Id { int get() { return _id; } void set(int value) { _id = value; } }

		property String^ PlateNumber { String^ get(); void set(String^ value); }
		property String^ Brand { String^ get(); void set(String^ value); }
		property String^ Model { String^ get(); void set(String^ value); }
		property String^ Fuel { String^ get(); void set(String^ value); }
		property int Year { int get(); void set(int value); }
		property int Seats { int get(); void set(int value); }

		/// The amount the owner wants to earn for every rental day.
		property Decimal OwnerDailyAmount { Decimal get(); void set(Decimal value); }

		property Owner^ OwnerInfo;
		property VehicleStatus Status;

		/// Price the customer pays per day (owner amount + 10% company commission).
		property Decimal CustomerDailyRate { Decimal get(); }

		[System::Xml::Serialization::XmlIgnore]
		virtual property VehicleType Type { VehicleType get() abstract; }

		/// POLYMORPHISM: every vehicle type describes itself differently.
		virtual String^ GetDetails() abstract;

		/// Factory that creates the correct subclass for a VehicleType.
		static Vehicle^ Create(VehicleType type);

		virtual String^ ToString() override;
	};

	public ref class Car : Vehicle
	{
	public:
		virtual property VehicleType Type { VehicleType get() override { return VehicleType::Car; } }
		virtual String^ GetDetails() override;
	};

	public ref class Van : Vehicle
	{
	public:
		virtual property VehicleType Type { VehicleType get() override { return VehicleType::Van; } }
		virtual String^ GetDetails() override;
	};

	public ref class Suv : Vehicle
	{
	public:
		virtual property VehicleType Type { VehicleType get() override { return VehicleType::SUV; } }
		virtual String^ GetDetails() override;
	};

	public ref class Bike : Vehicle
	{
	public:
		virtual property VehicleType Type { VehicleType get() override { return VehicleType::Bike; } }
		virtual String^ GetDetails() override;
	};

	public ref class Bus : Vehicle
	{
	public:
		virtual property VehicleType Type { VehicleType get() override { return VehicleType::Bus; } }
		virtual String^ GetDetails() override;
	};
}
