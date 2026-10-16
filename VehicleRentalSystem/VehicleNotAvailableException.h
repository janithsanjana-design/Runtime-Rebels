#pragma once

namespace VehicleRentalSystem
{
	using namespace System;

	/// Custom exception thrown when a vehicle cannot be booked.
	public ref class VehicleNotAvailableException : Exception
	{
	public:
		VehicleNotAvailableException(String^ vehicle)
			: Exception("Vehicle " + vehicle + " is not available for the selected dates.")
		{
		}
	};
}
