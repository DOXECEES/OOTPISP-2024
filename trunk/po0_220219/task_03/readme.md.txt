
# Лабораторная работа №3 #

## Правила перегрузки операций и принципы обработки исключений в C++ ##

## Вариант 5 ##
 
## Цель работы ##
Изучение правил перегрузки операций и принципов обработки исключений в C++. 


### Обработка исключения в ErrorCollection ###
```c++
 BaseError* ErrorCollection::operator[](int index) const {
    try {
        if (index < 0 || index >= m_count) {
            throw InvalidIndex(index);
        }
        return m_errors[index];
    }
    catch (const InvalidIndex& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return nullptr;
    }
}
```

### Перегрузка операторов класса ListError###

```c++
bool ListError::operator==(const BaseError& other) const {
    return dynamic_cast<const ListError*>(&other) != nullptr;
}
bool ListError::operator!=(const BaseError& other) const {
    return !(*this == other);
}
```

### Перегрузка операторов класса InvalidPointer###

```c++
bool InvalidPointer::operator==(const BaseError& other) const {
    const InvalidPointer* otherPtr = dynamic_cast<const InvalidPointer*>(&other);
    if (otherPtr) {
        return m_badAddr == otherPtr->m_badAddr;
    }
    return false;
}

bool InvalidPointer::operator!=(const BaseError& other) const {
    return !(*this == other);
}
```

### Перегрузка операторов класса InvalidIndex###

```c++
bool InvalidIndex::operator==(const BaseError& other) const {
    const InvalidIndex* otherPtr = dynamic_cast<const InvalidIndex*>(&other);
    if (otherPtr) {
        return m_index == otherPtr->m_index;
    }
    return false;
}
```

### Перегрузка операторов класса ListOverflow###

```c++
bool InvalidIndex::operator!=(const BaseError& other) const {
    return !(*this == other);
}

bool ListOverflow::operator==(const BaseError& other) const {
    return dynamic_cast<const ListOverflow*>(&other) != nullptr;
}

bool ListOverflow::operator!=(const BaseError& other) const {
    return !(*this == other);
}
```

