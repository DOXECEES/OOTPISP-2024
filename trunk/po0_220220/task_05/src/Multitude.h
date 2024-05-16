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
			(*arr)[count + 1] = element;
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
		return Lenght();
	};

	T operator[](const int index) const
	{
		return (*arr)[index];
	}

	void PushMaxToBegin();
	void DeleteMin();
	void AddAverageValueToVector();

private:
	std::unique_ptr<std::vector<T>> arr = std::make_unique<std::vector<T>>(2);
	int capacity = 2;
	int count = 0;
};

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
	average = average / static_cast<double>((*arr).size());
	std::ranges::for_each((*arr), [average](auto &i)
						  { i = i + average; });
}