
# Лабораторная работа №1 #

## Классы и объекты в С++ ##

## Вариант 4 ##
 

## Цель работы ##
Получить практические навыки реализации классов на С++.


### Блоки с кодом реализации конструкторов и деструктора ###
```c++
Product::Product()
{
	std::cout << "The default constructor was called " << this << std::endl;
}

Product::Product(const std::string& n_name, const std::string& n_code, const int n_amount)
	: name(n_name), code(n_code), amount(n_amount)
{
	std::cout << "Constructor with params was called " << this << std::endl;
}

```

### Фрагмент программы, показывающий использование указателя на объект и указателя на функцию ###

#### Указатель на объект ####

```c++
std::cout << box[1]->getName() << std::endl;
```

#### В элементe box содержится адрес объекта. Затем вызывается метод getName класса Product. Метод возвращает имя объекта. ####

#### Указатель на функцию ####

```c++
void (Product:: * current_fun)() const;
	
	current_fun = &Product::print;

	(ware.*current_fun)();
```

#### Адрес функции print записывается в указатель на функцию. Затем объект ware разыменовывает указатель и вызывает функцию print ####
