#include "CommissionCalculator.h"

namespace VehicleRentalSystem
{
	Decimal CommissionCalculator::CustomerPrice(Decimal ownerAmount)
	{
		return Math::Round(ownerAmount / (Decimal::One - Rate), 2);
	}

	Decimal CommissionCalculator::Commission(Decimal customerAmount)
	{
		return Math::Round(customerAmount * Rate, 2);
	}
}
