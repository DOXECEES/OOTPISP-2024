#pragma once

#include <iostream>

class Cash
{
public:
	Cash() = default;
	explicit Cash(const double Cash);
	Cash(const Cash &other) = default;
	~Cash() = default;

	Cash &operator=(const Cash &a) = default;
	bool operator==(const Cash &a) const;
	auto operator<=>(const Cash &a) const = default;
	Cash operator+(const Cash &a) const;
	Cash operator/(double val);

	friend std::ostream &operator<<(std::ostream &out, const Cash &a)
	{
		out << a.GetDolars() << " Dolars, " << a.Getcops() << " pennies" << std::endl;
		return out;
	}

	friend std::istream &operator>>(std::istream &in, Cash &a)
	{
		std::cout << "Enter amount of Dolars" << std::endl;
		in >> a.Dolars;
		std::cout << "Enter amount of pennies" << std::endl;
		in >> a.cops;
		return in;
	}

	inline int32_t Getcops() const { return cops; };
	inline int64_t GetDolars() const { return Dolars; };

	inline void SetCops(const int32_t p) { cops = p; };
	inline void SetDolars(const int64_t r) { Dolars = r; };

private:
	int64_t Dolars = 0;
	int32_t cops = 0;
};
