#pragma once

#include <string>
#include <iostream>


#ifndef Place_H
#define Place_H


class Place {
protected:

    static Place* head;
    static Place* lastObject;
public:
    std::string name;
    Place* next;
    Place();
    explicit Place(std::string_view name);
    virtual ~Place() = default;

    static void printHead();
    virtual void show();
    virtual void printVirtual();
    void print() const;
    Place* getHead();
    Place* getNext();
    void setNext(Place* next);
    Place* getThis();
    std::string getName() const;
};

class Region : public Place {
public:
    Region(std::string_view name, const int Population);
    ~Region() final = default;

    void printVirtual() override;
    void show() override;
private:
    int Population;
};
class City : public Place {
public:
    City(std::string_view name, const int Population);
    ~City() final = default;

    void printVirtual() override;
    void show() override;
private:
    int Population;
};
class Megalopolis : public Place {

public:

    Megalopolis(std::string_view name, const int Population);
    ~Megalopolis() final = default;

    void printVirtual() override;
    void show() override;
private:
    int Population;
};
#endif
