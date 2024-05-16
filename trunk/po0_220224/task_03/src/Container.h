#pragma once

#include <iostream>

#include "animal.h"
#include "mammal.h"
#include "reptile.h"
#include "bird.h"
#include "fish.h"

#include <vector>
#include <memory>
#include <stdexcept>

class Container
{
public:
    Container() = default;

    void ShowAll() const;
    void Add(Animal *_animal);
    int size() const;

    Animal *operator[](const int index);

    struct Node
    {
        explicit Node(Animal *_date)
            : date(_date)
        {
        }

        Animal *date;
        std::unique_ptr<Node> next = nullptr;
    };

private:
    int32_t _size = 0;
    std::unique_ptr<Node> head = nullptr;
};