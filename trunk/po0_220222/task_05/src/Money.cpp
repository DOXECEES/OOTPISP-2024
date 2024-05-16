#include "Money.h"
#include <memory>

Money::Money(const double a)

	:rubles(static_cast<long>(a)),
	kopeck(static_cast<int>((a - static_cast<int>(a)) * 100))
{
}

bool Money::operator==(const Money& a) const
{
	if (kopeck == a.kopeck && rubles == a.rubles)
		return true;
	else
		return false;
}


Money Money::operator+(const Money& a) const
{
	auto sum = std::make_unique<Money>();
	long RSum = this->GetR() + a.GetR();
	int KSum = this->GetK() + a.GetK();
	if (KSum > 100)
	{
		RSum++;
		KSum -= 100;
	}
	sum->SetK(KSum);
	sum->SetR(RSum);

	return *sum.get();

}