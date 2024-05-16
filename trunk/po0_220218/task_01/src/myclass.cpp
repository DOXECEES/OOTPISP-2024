#include "myclass.h"
#include <iostream>


Product::Product()
{
	std::cout << "The default constructor was called " << this << std::endl;
}

Product::Product(const std::string& n_name, const std::string& n_code, const int n_amount)
	: name(n_name), code(n_code), amount(n_amount)
{
	std::cout << "Constructor with params was called " << this << std::endl;
}

void Product::print() const
{
	std::cout << this->name;
	std::cout << this->code;
	std::cout << this->amount;
}

std::string Product::getName() const
{
	return name;
}
void Product::setName(const std::string& n_name)
{
	name = n_name;
}
std::string Product::getCode() const
{
	return code;
}
void Product::setCode(const std::string& n_code)
{
	code = n_code;
}
int Product::getAmount() const
{
	return amount;
}
void Product::setAmount(const int n_amount)
{
	amount = n_amount;
}
