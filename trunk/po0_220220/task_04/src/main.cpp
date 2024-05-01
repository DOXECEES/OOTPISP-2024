#include <iostream>
#include "Money.h"
#include "Set.h"

int main()
{
	Set<int> tmp;
	tmp.Add(1);
	tmp.Add(2);
	tmp.Add(2);
	tmp.Add(2);
	tmp.Add(3);
	tmp.Add(3);

	Set<int> tmp1;
	tmp.Add(5);
	tmp.Add(52);
	tmp.Add(22);
	tmp.Add(312);

	auto tmp2 = tmp + tmp1;
	std::cout << *tmp2;

	std::cout << "Element is " << tmp[2] << std::endl;

	std::cout << "Size is " << tmp() << std::endl;

	Set<Money> moneybag;

	moneybag.Add(Money(10.50));
	moneybag.Add(Money(3.28));
	moneybag.Add(Money(55.99));
	moneybag.Add(Money(1.1));
	moneybag.Add(Money(1.1));

	std::cout << moneybag;
}