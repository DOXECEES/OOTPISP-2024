#pragma once

#include <iostream>
#include "animal.h"

class Reptile : public Animal
{
public:
    enum class ReptileSpecies
    {
        SCALY,
        TURTLES,
        CROCODILES,
        BEAKHEADS
    };

    Reptile() = default;
    explicit Reptile(ReptileSpecies level);
    Reptile(const Reptile& other) = delete;

    ~Reptile() override = default;

    inline ReptileSpecies GetReptileSpecies() const { return reptilespecies; };
    inline void SetReptileSpecies(ReptileSpecies level) { reptilespecies = level; };

    void Print() const override;

    Reptile& operator=(const Reptile& right) = default;
    bool operator==(const Reptile& right) const;

private:
    ReptileSpecies reptilespecies = ReptileSpecies::SCALY;
};
