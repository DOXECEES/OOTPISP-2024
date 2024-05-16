#ifndef ERROR_COLLECTION_H
#define ERROR_COLLECTION_H

#include "Errors.h"
#include <vector>
#include <memory>

class ErrorCollection {
    std::vector<std::unique_ptr<BaseError>> m_errors;
public:
    explicit ErrorCollection(int count);
    ~ErrorCollection() = default;

    BaseError* operator[] (int index) const;
    std::unique_ptr<BaseError>& operator[](int index);

};

#endif 
