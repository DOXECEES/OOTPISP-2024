#pragma once
#pragma once

#include <iostream>
#include <string>

#include "animal.h"

class Bird : public Animal
{
public:
    enum class Squads : int8_t
    {

        PENGUINS,
        OSTRICH,
        PASSERINES,
        GALLIFORMES
    };

    Bird() = default;
    explicit Bird(Squads ordersofbirds);
    Bird(const Bird& other) = delete;

    ~Bird() override = default;

    void Print() const override;

    inline void SetSquads(Squads ordersofbirds) { squads = ordersofbirds; };

    bool operator==(const Bird& right) const;

private:
    Squads squads = Squads::PENGUINS;
};