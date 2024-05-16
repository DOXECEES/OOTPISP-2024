#include <iostream>
#include <string>

#include "Container.h"

#include "fish.h"
#include "bird.h"
#include "reptile.h"
#include "mammal.h"

int main()
{
    Container arr;

    Mammal mammal1("First mammal");
    Mammal mammal2("Second mammal");

    mammal1.SetType(Mammal::Type::CARNIVORA);
    mammal2.SetType(Mammal::Type::ARTIODACTYLA);

    if (mammal1 == mammal2)
    {
        std::cout << "Mammals are eq" << std::endl;
    }
    else
    {
        std::cout << "Mammals are uneq" << std::endl;
    }

    arr.Add(&mammal1);
    arr.Add(&mammal2);

    Reptile reptile1(Reptile::ReptileSpecies::TURTLES);
    Reptile reptile2(Reptile::ReptileSpecies::BEAKHEADS);

    if (reptile1 == reptile2)
    {
        std::cout << "Reptiles are eq" << std::endl;
    }
    else
    {
        std::cout << "Reptiles are uneq" << std::endl;
    }
    reptile2 = reptile1;

    arr.Add(&reptile1);
    arr.Add(&reptile2);

    Bird bird1(Bird::Squads::PENGUINS);
    Bird bird2(Bird::Squads::PASSERINES);

    if (bird1 == bird2)
    {
        std::cout << "Birds are eq" << std::endl;
    }
    else
    {
        std::cout << "Birds are uneq" << std::endl;
    }

    arr.Add(&bird1);
    arr.Add(&bird2);

    Fish fish1(15);
    Fish fish2(21);

    if (fish1 == fish2)
    {
        std::cout << "Fishs are eq" << std::endl;
    }
    else
    {
        std::cout << "Fish are uneq" << std::endl;
    }

    arr.Add(dynamic_cast<Animal*>(&fish1));
    arr.Add(dynamic_cast<Animal*>(&fish2));

    std::cout << "Count of animals: " << arr.size() << std::endl;
    arr.ShowAll();

    arr[8]->Print();
}