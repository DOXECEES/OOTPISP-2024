#include "reptile.h"

Reptile::Reptile(ReptileSpecies view)
    : Animal("Reptile"), reptilespecies(view)
{
}

void Reptile::Print() const
{
    Animal::Print();
    std::cout << "Reptile Species: ";
    switch (static_cast<int>(reptilespecies))
    {
    case 0:
    {
        std::cout << "SCALY";
        break;
    }
    case 1:
    {
        std::cout << "TURTLES";
        break;
    }
    case 2:
    {
        std::cout << "CROCODILES";
        break;
    }
    case 3:
    {
        std::cout << "BEAKHEADS";
        break;
    }
    default:
    {
        std::cout << "Unknown reptil especies ";
        break;
    }
    }
    std::cout << std::endl;
}

bool Reptile::operator==(const Reptile& right) const
{
    return this->reptilespecies == right.reptilespecies;
}