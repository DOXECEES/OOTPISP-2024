
# Лабораторная работа №4 #

## Шаблоны классов ##

## Вариант 5 ##
 

## Цель работы ##
Создание консольного приложения, состоящего из нескольких файлов в системе  программирования Visual Studio. Реализация шаблона класса-контейнера. 

### Перегрузка оператора вывода и фунция Show в классе Vector ###
```c++
template <class T>
std::ostream& operator<<(std::ostream& out, const Vector<T>& a)
{
    a.Show();
    return out;
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
```

### Перегрузка оператора вывода в классе Time###

```c++
friend std::ostream& operator<<(std::ostream& out, const Time& a)
    {
        out << a.GetMin() << ":" << a.GetSec() << " ";
        return out;
    }
```

### Перегрузка оператора + класса Vector ###

```c++
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
```

### Перегрузка оператора () и функции Size класса Vector для определения размера векторов ###

```c++

template <class T>
int Vector<T>::operator()() const
{
    return Size();
};
template <class T>
size_t Vector<T>::Size() const
{
    return listElem.size();
}
```

### Перегрузка оператора [] класса Vector для обращения к элементу по индексу ###

```c++
template <class T>
T Vector<T>::operator[](const int index) const
{
    auto it = listElem.begin();
    std::advance(it, index);
    return *it;
}
```
