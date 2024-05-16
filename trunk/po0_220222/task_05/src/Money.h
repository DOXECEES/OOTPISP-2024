#pragma once
#ifndef MONEYH
#define MONEYH
#include <iostream>


class Money
{
public:
	Money() = default;
	explicit Money(const double a);
	Money(const Money& other) = default;
	~Money() = default;
	Money& operator=(const Money& a) = default;
	bool operator==(const Money& a) const;
	auto operator<=>(const Money& a) const = default;
	Money operator+(const Money& a) const;


	friend std::ostream& operator << (std::ostream& out, const Money& a)
	{
		out << a.GetR() << ',' << a.GetK() << std::endl;
		return out;
	}

	friend std::istream& operator >> (std::istream& in, Money& a)
	{
		std::cout << "Enter amount of rubles" << std::endl;
		in >> a.rubles;
		std::cout << "Enter amount of kopeck" << std::endl;
		in >> a.kopeck;
		return in;
	}

	inline int GetK() const { return kopeck; };
	inline long GetR() const { return rubles; };
	inline void SetK(const int k) { kopeck = k; };
	inline void SetR(const long r) { rubles = r; };

private:
	long rubles = 0;
	int kopeck = 0;
};

#endif
