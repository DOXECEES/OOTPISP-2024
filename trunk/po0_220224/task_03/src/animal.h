#pragma once

#include <string_view>
#include <exception>
#include <iostream>

class Animal
{
public:
    Animal() = default;
    explicit Animal(std::string_view _message);
    Animal(const Animal &other) = delete;

    virtual ~Animal() = default;

    virtual void Print() const;

    Animal &operator=(const Animal &right) = default;
    bool operator==(const Animal &right) const = default;

private:
    std::string_view message = "";
};