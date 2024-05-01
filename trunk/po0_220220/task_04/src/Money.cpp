#include "Money.h"

Money::Money(const double money)
	: rubles(static_cast<int64_t>(money)),
	  penny(static_cast<int32_t>((money - static_cast<int32_t>(money)) * 100))
{
}

bool Money::operator==(const Money &a) const
{
	return (penny == a.penny && rubles == a.rubles);
}
