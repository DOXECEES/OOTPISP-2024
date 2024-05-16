#pragma once
#include <iostream>
#include <memory>
#include <vector>

template <typename T>
class Multitude
{

public:
	Multitude() = default;
	~Multitude() = default;

	void Insert(const T &element)
	{
		if (!IsExist(element))
		{
			if (count >= capacity)
			{
				auto newarr = std::make_unique<std::vector<T>>(capacity * 2);
				for (int i = 0; i < count; ++i)
				{
					(*newarr)[i] = (*arr)[i];
				}

				arr = std::move(newarr);
				capacity *= 2;
			}
			(*arr)[count++] = element;
		}
	}

	void Delete(const T &element)
	{
		for (int i = 0; i < count; ++i)
		{
			if (arr[i] == element)
			{
				for (int j = i; j < count - 1; ++j)
				{
					arr[j] = arr[j + 1];
				}
				--count;
				return;
			}
		}
	}

	bool IsExist(const T &element) const
	{
		for (int i = 0; i < count; ++i)
		{
			if ((*arr)[i] == element)
			{
				return true;
			}
		}
		return false;
	}

	int Lenght() const
	{
		return count;
	}

	void Show() const
	{
		std::cout << "{ ";
		for (int i = 0; i < count; ++i)
		{
			std::cout << (*arr)[i] << " ";
		}
		std::cout << "}" << std::endl;
	}

	int operator()() const
	{
		return Size();
	};

	T operator[](const int index) const
	{
		return (*arr)[index];
	}

	auto operator+(const Multitude<T> &Multitude) const
	{
		auto newMultitude = std::make_unique<Multitude<T>>();

		for (int i = 0; i < Multitude.Lenght(); i++)
		{
			newMultitude->Insert(Multitude[i]);
		}
		for (int i = 0; i < count; i++)
		{
			newMultitude->Add((*arr)[i]);
		}

		return newMultitude;
	}

	void PushMaxToBegin();
	void DeleteMin();
	void AddAverageValueToVector();

	friend std::ostream &operator<< <T>(std::ostream &out, const Multitude<T> &a);
	friend std::istream &operator>> <T>(std::istream &in, Multitude<T> &a);

private:
	std::unique_ptr<std::vector<T>> arr = std::make_unique<std::vector<T>>(2);
	int capacity = 2;
	int count = 0;
};

template <class T>
std::ostream &operator<<(std::ostream &out, const Multitude<T> &a)
{
	a.print();
	return out;
}

template <class T>
std::istream &operator>>(std::istream &in, Multitude<T> &a)
{
	for (int i = 0; i < a(); i++)
	{
		T temp;
		in >> temp;
		a.Add(temp);
	}
	return in;
}

template <class T>
inline void Multitude<T>::PushMaxToBegin()
{
	auto max = std::ranges::max_element(*arr);
	(*arr).insert((*arr).begin(), *max);
}

template <class T>
inline void Multitude<T>::DeleteMin()
{
	auto min = std::ranges::min_element(*arr);
	(*arr).erase(min);
}

template <class T>
inline void Multitude<T>::AddAverageValueToVector()
{
	auto average = std::accumulate((*arr).begin(), (*arr).end(), T());
	average = average / (*arr).size();
	std::ranges::for_each((*arr), [average](auto &i)
						  { i = i + average; });
}