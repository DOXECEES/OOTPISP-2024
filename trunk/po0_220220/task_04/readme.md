
# Лабораторная работа №4 #

## Шаблоны классов ##

## Вариант 6 ##
 

## Цель работы ##
Создание консольного приложения, состоящего из нескольких файлов в системе  программирования Visual Studio. Реализация шаблона класса-контейнера. 

### Перегрузка операций ввода/вывода в классе Set ###
```c++
 template <class T>
std::ostream &operator<<(std::ostream &out, const Set<T> &a)
{
	a.print();
	return out;
}

template <class T>
std::istream &operator>>(std::istream &in, Set<T> &a)
{
	for (int i = 0; i < a(); i++)
	{
		T temp;
		in >> temp;
		a.Add(temp);
	}
	return in;
}
```

### Перегрузка операторов ввода/вывода в классе Money ###

```c++
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
```

### Перегрузка оператора + класса Set для объединения множеств ###

```c++
auto operator+(const Set<T> &set) const
	{
		auto newSet = std::make_unique<Set<T>>();

		for (int i = 0; i < set.Size(); i++)
		{
			newSet->Add(set[i]);
		}
		for (int i = 0; i < count; i++)
		{
			newSet->Add(elements[i]);
		}

		return newSet;
	}
```

### Перегрузка оператора () класса Set для определения размера множества ###

```c++
int operator()() const
{
	return Size();
};
```

### Перегрузка оператора [] класса Set для обращения к элементу по индексу ###

```c++
T operator[](const int index) const
{
	return elements[index];
}
```
