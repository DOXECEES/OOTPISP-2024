#include "animal.h"
#include <typeinfo>

Animal::Animal(std::string_view _message) : message(_message) {}

void Animal::Print() const
{
    std::cout << "[" << message << "]" << std::endl;
}