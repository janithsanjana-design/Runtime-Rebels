#pragma once
#include "IEntity.h"

namespace VehicleRentalSystem
{
	using namespace System;

	/// ABSTRACTION + INHERITANCE: common data of every person in the system.
	/// Owner, Customer and Driver inherit from this class.
	/// ENCAPSULATION: fields are private; the properties validate their values.
	public ref class Person abstract
	{
	private:
		String^ _name;
		String^ _nic;
		String^ _phone;
		String^ _address;

	public:
		Person();

		property String^ Name { String^ get(); void set(String^ value); }
		property String^ Nic { String^ get(); void set(String^ value); }
		property String^ Phone { String^ get(); void set(String^ value); }
		property String^ Address { String^ get(); void set(String^ value); }

		/// POLYMORPHISM: each subclass reports its own role.
		virtual String^ GetRole() abstract;

	protected:
		/// Shared helper: trims text and rejects empty values.
		static String^ Required(String^ value, String^ field);
	};

	/// A vehicle owner who earns money when the vehicle is hired.
	public ref class Owner : Person
	{
	private:
		String^ _bankAccount;

	public:
		Owner();
		property String^ BankAccount { String^ get(); void set(String^ value); }
		virtual String^ GetRole() override { return "Vehicle Owner"; }
	};

	/// A person who hires a vehicle.
	public ref class Customer : Person
	{
	public:
		virtual String^ GetRole() override { return "Customer"; }
	};

	/// A driver that a vehicle-hiring customer may request.
	public ref class Driver : Person, IEntity
	{
	private:
		int _id;
		String^ _licenceNumber;
		Decimal _dailyCharge;

	public:
		Driver();

		virtual property int Id { int get() { return _id; } void set(int value) { _id = value; } }

		property String^ LicenceNumber { String^ get(); void set(String^ value); }
		property DateTime LicenceExpiry;
		property Decimal DailyCharge { Decimal get(); void set(Decimal value); }

		/// True while the driver is on an active booking.
		property bool IsBusy;

		virtual String^ GetRole() override { return "Driver"; }
	};
}
