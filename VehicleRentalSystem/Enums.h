#pragma once

namespace VehicleRentalSystem
{
	/// Kinds of vehicle that can be registered.
	public enum class VehicleType { Car, Van, SUV, Bike, Bus };

	/// Whether a vehicle can currently be hired.
	public enum class VehicleStatus { Available, Rented };

	/// Life cycle of a booking.
	public enum class BookingStatus { Active, Completed };
}
