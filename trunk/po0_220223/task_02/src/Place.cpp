#include "Place.h"
#include <iostream>
#include <string>

using namespace std;

Place::Place() {
    if (head == nullptr) {
        head = this;
    }
    next = nullptr;
    if (lastObject != nullptr) {
        lastObject->setNext(this);
    }
    lastObject = this;
    name = "name";
}
Place::Place(string_view name1) {
    if (head == nullptr) {
        head = this;
    }
    next = nullptr;
    if (lastObject != nullptr) {
        lastObject->setNext(this);
    }
    lastObject = this;
    name = name1;
}
void Place::printHead() {
    Place* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->getName() << endl;
        ptr = ptr->next;
    }
}
void Place::show() {
    cout << " " << endl;
    Place* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->getName() << endl;
        ptr = ptr->next;
    }
}
void Place::printVirtual() {
    cout << "Place (virtual function)" << endl;
}

void Place::print() const {
    cout << "Place" << endl;
}

Place* Place::getHead() {
    return head;
}
Place* Place::getNext() {
    return next;
}
void Place::setNext(Place* next1) {
    next = next1;
}
Place* Place::getThis() {
    return this;
}
string Place::getName()  const {
    return name;
}
Place* Place::head = nullptr;
Place* Place::lastObject = nullptr;


Region::Region(string_view name1, const int Population1)
    : Population(Population1) {
    name = name1;
}
void Region::printVirtual() {
    cout << "Region (virtual function)" << endl;
}
void Region::show() {
    Place* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->getName() << " - Population: " << Population << endl;
        ptr = ptr->getNext();
        if (this->getNext() == ptr) {
            break;
        }
    }
}
City::City(string_view name1, const int Population1)
    : Population(Population1) {
    name = name1;
}
void City::printVirtual() {
    cout << "City (virtual function)" << endl;
}
void City::show() {
    Place* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->getName() << " - Population: " << Population << endl;
        ptr = ptr->getNext();
        if (this->getNext() == ptr) {
            break;
        }
    }

}




Megalopolis::Megalopolis(string_view name1, const int Population1)
    : Population(Population1) {
    name = name1;
}
void Megalopolis::printVirtual() {
    cout << "Megalopolis (virtual function)" << endl;
}
void Megalopolis::show() {
    Place* ptr = head;
    while (ptr != nullptr) {
        cout << ptr->getName() << " - Population: " << Population << endl;
        ptr = ptr->getNext();
        if (this->getNext() == ptr) {
            break;
        }
    }

}
