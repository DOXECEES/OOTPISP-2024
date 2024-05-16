#include "bird.h"

Bird::Bird(Squads ordersofbirds)
    : Animal("Bird"), squads(ordersofbirds)
{
}

void Bird::Print() const
{
    Bird::Print();
    std::cout << "Orders of the bird: ";
    switch (static_cast<int>(squads))
    {
    case 0:
    {
        std::cout << "PENGUINS";
        break;
    }
    case 1:
    {
        std::cout << "OSTRICH";
        break;
    }
    case 2:
    {
        std::cout << "PASSERINES";
        break;
    }
    case 3:
    {
        std::cout << "GALLIFORMES";
        break;
    }
    default:
    {
        std::cout << "There isn't such squads";
        break;
    }
    }
    std::cout << std::endl;
}

bool Bird::operator==(const Bird& right) const
{
    return (this->squads == right.squads);
}