#pragma once

namespace VehicleRentalSystem
{
	using namespace System;

	/// The 10% company commission rule lives only here.
	public ref class CommissionCalculator abstract sealed
	{
	public:
		/// 0.10 = 10%
		static property Decimal Rate { Decimal get() { return Decimal(1, 0, 0, false, 1); } }

		/// Owner wants 9,000 -> customer pays 10,000 (company keeps 1,000).
		static Decimal CustomerPrice(Decimal ownerAmount);

		/// Company's 10% of an amount paid by the customer.
		static Decimal Commission(Decimal customerAmount);
	};
}
