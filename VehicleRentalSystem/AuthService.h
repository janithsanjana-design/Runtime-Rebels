#pragma once

namespace VehicleRentalSystem
{
	using namespace System;

	/// Very simple admin login (course project).
	public ref class AuthService abstract sealed
	{
	public:
		static property String^ AdminUser { String^ get() { return "admin"; } }
		static property String^ AdminPassword { String^ get() { return "admin123"; } }

		static bool Login(String^ user, String^ password)
		{
			return user == AdminUser && password == AdminPassword;
		}
	};
}
