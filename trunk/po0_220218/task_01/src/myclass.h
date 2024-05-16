#ifndef MYCLASSH
#define MYCLASSH

#include <string>

class Product {
public:
	Product();
	Product(const std::string& n_name, const std::string& n_code, int n_amount);
	void print() const;
	std::string getName() const;
	void setName(const std::string& n_name);
	std::string getCode() const;
	void setCode(const std::string& n_code);
	int getAmount() const;
	void setAmount(const int n_amount);

private:
	std::string name = "";
	std::string code = "";
	int amount = 0;
};
#endif
