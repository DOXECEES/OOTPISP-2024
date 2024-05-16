#ifndef ERRORS_H
#define ERRORS_H

#include <iostream>

class BaseError {
public:
    virtual void Print() const = 0;
    virtual ~BaseError() = default;

    bool operator==(const BaseError& other) const; 
};

class InvalidPointer : public BaseError {
    unsigned char* m_badAddr;
public:
    explicit InvalidPointer(unsigned char* badAddr);
    void Print() const override;
    const char* what() const noexcept;


};


class ListError : public BaseError {
public:
    void Print() const override;

};

class InvalidIndex : public BaseError {
    int m_index;
public:
    explicit InvalidIndex(int index);
    void Print() const override;
    const char* what() const noexcept;

};

class ListOverflow : public BaseError {
public:
    void Print() const override;

};

#endif
