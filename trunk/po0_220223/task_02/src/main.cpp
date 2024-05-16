#include <iostream>
#include <string>
#include "Place.h"
using namespace std;
int main() {
    auto comp1 = Place("name1");
    auto comp2 = Region("name2", 40);
    auto comp3 = City("name3", 15);
    auto comp4 = Megalopolis("name4", 17);
    comp1.show();
    comp2.show();
    comp3.show();
    comp4.show();
    Place::printHead();

    return 0;
}
