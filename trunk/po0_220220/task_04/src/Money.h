#pragma once

#include <iostream>

class Money
{
public:
	Money() = default;
	explicit Money(const double money);
	Money(const Money &other) = default;
	~Money() = default;

	Money &operator=(const Money &a) = default;
	bool operator==(const Money &a) const;

	friend std::ostream &operator<<(std::ostream &out, const Money &a)
	{
		out << a.GetRubles() << " Rubles, " << a.GetPenny() << " pennies" << std::endl;
		return out;
	}

	friend std::istream &operator>>(std::istream &in, Money &a)
	{
		std::cout << "Enter amount of rubles" << std::endl;
		in >> a.rubles;
		std::cout << "Enter amount of pennies" << std::endl;
		in >> a.penny;
		return in;
	}

	inline int32_t GetPenny() const { return penny; };
	inline int64_t GetRubles() const { return rubles; };

	inline void SetPenny(const int32_t p) { penny = p; };
	inline void SetRubles(const int64_t r) { rubles = r; };

private:
	int64_t rubles = 0;
	int32_t penny = 0;
};
