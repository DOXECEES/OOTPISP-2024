#include "ErrorCollection.h"
#include <iostream>

ErrorCollection::ErrorCollection(int count) {
    m_errors.resize(count);
}

BaseError* ErrorCollection::operator[](int index) const {
    try {
        if (index < 0 || index >= m_errors.size()) {
            throw InvalidIndex(index);
        }
        return m_errors[index].get();
    }
    catch (const InvalidIndex& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return nullptr;
    }
}

std::unique_ptr<BaseError>& ErrorCollection::operator[](int index) {
    try {
        if (index < 0 || index >= m_errors.size()) {
            throw InvalidIndex(index);
        }
        return m_errors[index]; 
    }
    catch (const InvalidIndex& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        static std::unique_ptr<BaseError> nullPtr = nullptr;
        return nullPtr;
    }
}



