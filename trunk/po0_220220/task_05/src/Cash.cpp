#include "Cash.h"

Cash::Cash(const double Cash)
	: Dolars(static_cast<int64_t>(Cash)),
	  cops(static_cast<int32_t>((Cash - static_cast<int32_t>(Cash)) * 100))
{
}

bool Cash::operator==(const Cash &a) const
{
	return (cops == a.cops && Dolars == a.Dolars);
}
Cash Cash::operator+(const Cash &a) const
{
	Cash res;
	res.Dolars = Dolars + a.Dolars;
	res.cops = cops + a.cops;

	if (res.cops >= 100)
	{
		res.Dolars += res.cops / 100;
		res.cops %= 100;
	}

	return res;
}

Cash Cash::operator/(double val)
{
	this->cops /= static_cast<int32_t>(val);
	this->Dolars /= static_cast<int32_t>(val);
	return *this;
}
