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
Money Money::operator+(const Money &a) const
{
	Money result;
	result.rubles = rubles + a.rubles;
	result.penny = penny + a.penny;

	if (result.penny >= 100)
	{
		result.rubles += result.penny / 100;
		result.penny %= 100;
	}

	return result;
}

Money Money::operator/(double val)
{
	this->penny /= val;
	this->rubles /= val;
	return *this;
}
