#include "mammal.h"

Mammal::Mammal(std::string_view _message)
    : Animal(_message)
{
}

void Mammal::Print() const
{
    Mammal::Print();
    std::cout << "Mammal: mammal_type: ";
    switch (static_cast<int>(mammal_Type))
    {
    case 0:
    {
        std::cout << "PRIMATES";
        break;
    }
    case 1:
    {
        std::cout << "CARNIVORA";
        break;
    }
    case 2:
    {
        std::cout << "RODENTIA ";
        break;
    }
    case 3:
    {
        std::cout << "ARTIODACTYLA";
        break;
    }
    case 4:
    {
        std::cout << "CETACEA";
        break;
    }
    case 5:
    {
        std::cout << "OTHER";
        break;
    }
    default:
    {
        std::cout << "There isn't such mammal_type";
        break;
    }
    }
    std::cout << std::endl;
}

bool Mammal::operator==(const Mammal& right) const
{
    return (this->mammal_Type == right.mammal_Type);
}