#pragma once
#include <iostream>

template <typename T>
class Set
{

public:
	Set() : elements(new T[2]), capacity(2), count(0) {}

	~Set()
	{
		delete[] elements;
	}

	void Add(const T &element)
	{
		if (!Contains(element))
		{
			if (count >= capacity)
			{
				T *newElements = new T[capacity * 2];
				for (int i = 0; i < count; ++i)
				{
					newElements[i] = elements[i];
				}
				delete[] elements;
				elements = newElements;
				capacity *= 2;
			}
			elements[count++] = element;
		}
	}

	void Remove(const T &element)
	{
		for (int i = 0; i < count; ++i)
		{
			if (elements[i] == element)
			{
				for (int j = i; j < count - 1; ++j)
				{
					elements[j] = elements[j + 1];
				}
				--count;
				return;
			}
		}
	}

	bool Contains(const T &element) const
	{
		for (int i = 0; i < count; ++i)
		{
			if (elements[i] == element)
			{
				return true;
			}
		}
		return false;
	}

	int Size() const
	{
		return count;
	}

	void print() const
	{
		std::cout << "{ ";
		for (int i = 0; i < count; ++i)
		{
			std::cout << elements[i] << " ";
		}
		std::cout << "}" << std::endl;
	}

	int operator()() const
	{
		return Size();
	};

	T operator[](const int index) const
	{
		return elements[index];
	}

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

	friend std::ostream &operator<< <T>(std::ostream &out, const Set<T> &a);
	friend std::istream &operator>> <T>(std::istream &in, Set<T> &a);

private:
	T *elements;
	int capacity;
	int count;
};

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