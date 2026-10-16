#pragma once
#include "Booking.h"

namespace VehicleRentalSystem
{
	using namespace System;
	using namespace System::Collections::Generic;

	/// Totals for the dashboard cards.
	public ref class DashboardSummary
	{
	public:
		property int TotalVehicles;
		property int AvailableVehicles;
		property int RentedVehicles;
		property Decimal TotalIncome;
		property Decimal OwnerPayable;
		property Decimal CompanyProfit;
	};

	/// One line of the "income vehicle-wise" report.
	public ref class VehicleIncomeRow
	{
	public:
		property String^ Vehicle;
		property String^ Owner;
		property int Rentals;
		property Decimal Income;
		property Decimal OwnerPayable;
		property Decimal CompanyProfit;
	};

	/// Income = what customers pay for the vehicle (driver fees go to the driver).
	/// The owner gets 90% of it, the company keeps 10%.
	public ref class ReportService abstract sealed
	{
	public:
		static DashboardSummary^ GetSummary();
		static List<VehicleIncomeRow^>^ GetVehicleIncome();
		static List<Booking^>^ GetActiveBookings();
	};
}
