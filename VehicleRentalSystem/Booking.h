#pragma once
#include "Enums.h"
#include "IEntity.h"
#include "Person.h"

namespace VehicleRentalSystem
{
	using namespace System;

	/// ASSOCIATION: a booking links a Customer, a Vehicle and (optionally) a Driver.
	/// All money values are stored when the booking is made.
	public ref class Booking : IEntity
	{
	private:
		int _id;

	public:
		Booking();

		virtual property int Id { int get() { return _id; } void set(int value) { _id = value; } }

		property Customer^ CustomerInfo;

		property int VehicleId;
		property String^ VehicleName;

		/// 0 when the customer did not ask for a driver.
		property int DriverId;
		property String^ DriverName;

		property DateTime FromDate;
		property DateTime ToDate;
		property int Days;

		property Decimal VehicleDailyRate;
		property Decimal DriverDailyCharge;
		property Decimal VehicleCost;
		property Decimal DriverCost;
		property Decimal Advance;

		property BookingStatus Status;
		property DateTime CreatedOn;

		property Decimal Total { Decimal get(); }
		property Decimal Balance { Decimal get(); }

		/// Company's 10% of the vehicle rental.
		property Decimal CompanyCommission { Decimal get(); }

		/// What the vehicle owner receives (90% of the vehicle rental).
		property Decimal OwnerShare { Decimal get(); }
	};
}
