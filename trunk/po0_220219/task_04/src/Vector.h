#pragma once

#include <iostream>
#include <memory>
#include <list> 

template <typename T>
class Vector
{
public:
    Vector() = default;
    ~Vector() = default;

    void Add(const T& element);
    size_t Size() const;
    int operator()() const;
    T operator[](const int index) const;
    auto operator+(const T k) const;
    auto operator+(const Vector<T>& vector) const;
    void operator*=(const T& k);
    auto operator*(const T& k) const;
    void Show() const;

    inline int GetCapacity() const { return capacity; };

    friend std::ostream& operator<< <T>(std::ostream& out, const Vector<T>& a);

private:
    std::unique_ptr<std::list<T>> vectorElem = std::make_unique<std::list<T>>(2);
    std::list<T> listElem;
    int capacity = 0;
};

template <class T>
void Vector<T>::operator*=(const T& k)
{
    for (auto& elem : listElem)
    {
        elem *= k;
    }
}

template <class T>
auto Vector<T>::operator*(const T& k) const
{
    auto newVector = std::make_unique<Vector<T>>();

    for (int i = 0; i < capacity; i++)
    {
        newVector->Add((*vectorElem)[i] * k);
    }

    return *newVector;
}

template <class T>
void Vector<T>::Add(const T& element)
{
    listElem.push_back(element);
}

template <class T>
auto Vector<T>::operator+(const Vector<T>& vector) const
{
    auto newVector = Vector<T>();

    auto it1 = listElem.begin();
    auto it2 = vector.listElem.begin();

    while (it1 != listElem.end() && it2 != vector.listElem.end())
    {
        newVector.Add(*it1 + *it2);
        ++it1;
        ++it2;
    }

    while (it1 != listElem.end())
    {
        newVector.Add(*it1);
        ++it1;
    }

    while (it2 != vector.listElem.end())
    {
        newVector.Add(*it2);
        ++it2;
    }

    return newVector;
}

template <class T>
size_t Vector<T>::Size() const
{
    return listElem.size();
}


template <class T>
int Vector<T>::operator()() const
{
    return Size();
};

template <class T>
T Vector<T>::operator[](const int index) const
{
    auto it = listElem.begin();
    std::advance(it, index);
    return *it;
}

template <class T>
auto Vector<T>::operator+(const T k) const
{
    auto newVector = Vector<T>();

    for (const auto& elem : listElem)
    {
        newVector.Add(elem + k);
    }

    return newVector;
}

template <class T>
void Vector<T>::Show() const
{
    std::cout << "{ ";
    for (const auto& elem : listElem)
    {
        std::cout << elem << " ";
    }
    std::cout << "}" << std::endl;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& a)
{
    a.Show();
    return out;
}
