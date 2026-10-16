#pragma once
#include "IEntity.h"

namespace VehicleRentalSystem
{
	using namespace System::Collections::Generic;

	/// INTERFACE: the operations every repository must provide.
	generic<typename T> where T : IEntity
	public interface class IRepository
	{
		void Add(T item);
		void Update(T item);
		void Remove(int id);
		T GetById(int id);
		List<T>^ GetAll();
	};
}
