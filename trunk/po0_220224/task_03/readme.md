# Лабораторная работа №2 #

## Правила перегрузки операций и принципы обработки исключений в С++ ##

## Вариант 9 ##

## Цель работы ##

Изучить правила перегрузки операций и принцивы обработки исключений в С++

### Обработка исключаний для Animal \*operator [](const int index) ###

```c++
    
    try
    {
        if (index < 0 || index >= collectionSize)
            throw std::out_of_range("out of range");

        auto ptr = std::move(head);
        for (int i = 0; i < index; i++)
        {
            ptr = std::move(ptr->next);
        }
        return ptr->date;
    }
    catch (const std::out_of_range& err)
    {
        std::cout << err.what() << std::endl;
        Animal animal;
        return nullptr;
    }

```

## Перегрузка операторов ##

### Class Reptile ###

```c++
    
bool Reptile::operator==(const Reptile& right) const
{
    return this->reptilespecies == right.reptilespecies;
}
```

### Class Fish ###

```c++

bool Fish::operator==(const Fish& right) const
{
    return (this->fishweight == right.fishweight);
}
```

### Class Bird ###

```c++

bool Bird::operator==(const Bird& right) const
{
    return (this->squads == right.squads);
}
```

### Class Mammal ###

```c++

bool Mammal::operator==(const Mammal& right) const
{
    return (this->mammal_Type == right.mammal_Type);
}
```
