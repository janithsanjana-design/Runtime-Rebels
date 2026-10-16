#pragma once

namespace VehicleRentalSystem
{
	/// INTERFACE: anything stored in a repository has an integer Id.
	public interface class IEntity
	{
		property int Id
		{
			int get();
			void set(int value);
		}
	};
}
