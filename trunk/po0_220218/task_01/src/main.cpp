#include <iostream>
#include "myclass.h"
#include <vector>
#include <memory>

int main()
{
	std::string n_name;
	std::cin >> n_name;
	std::string n_code;
	std::cin >> n_code;
	int amount;
	std::cin >> amount;
	Product good(n_name, n_code, amount);
	void (Product:: * current_fun)() const;

	current_fun = &Product::print;

	std::vector <Product*> box;

	box.push_back(&good);

	Product ware;

	box.push_back(&ware);

	(ware.*current_fun)();

	std::cout << box[1]->getName() << std::endl;

	std::array<Product, 3> n_box = {
		Product("Ложка", "1234", 1000),
		Product("Вилка", "4321", 2000),
		Product("Нож", "1111", 0) };

	std::cout << n_box[1].getName();
}