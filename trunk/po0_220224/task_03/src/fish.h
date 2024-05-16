#pragma once

#include "animal.h"

class Fish : public Animal
{
public:
    Fish() = default;
    explicit Fish(const uint8_t fishweig);
    Fish(const Fish& other) = delete;

    ~Fish() override = default;

    void Print() const override;

    inline void SetExperienceNumber(const uint8_t fishweig) { fishweight = fishweig; };

    Fish& operator=(const Fish& right) = default;
    bool operator==(const Fish& right) const;

private:
    uint8_t fishweight = 0;
};