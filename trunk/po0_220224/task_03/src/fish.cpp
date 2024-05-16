#include "fish.h"

Fish::Fish(const uint8_t fishweig)
    : Animal("Fish"), fishweight(fishweig)
{
}

void Fish::Print() const
{
    Animal::Print();
    std::cout << ": " << static_cast<int>(fishweight) << std::endl;
}

bool Fish::operator==(const Fish& right) const
{
    return (this->fishweight == right.fishweight);
}