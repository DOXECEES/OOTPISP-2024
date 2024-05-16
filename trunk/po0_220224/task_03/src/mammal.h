#pragma once

#include <string>
#include <string_view>
#include "animal.h"

class Mammal : public Animal
{
public:
    enum class Type : int8_t
    {
        PRIMATES,
        CARNIVORA,
        RODENTIA,
        ARTIODACTYLA,
        CETACEA,
        OTHER
    };

    Mammal() = default;
    explicit Mammal(std::string_view _message);
    Mammal(const Mammal& other) = delete;

    ~Mammal() override = default;

    void Print() const override;

    inline void SetType(const Type type) { mammal_Type = type; };

    bool operator==(const Mammal& right) const;

private:
    Type mammal_Type = Type::OTHER;
};