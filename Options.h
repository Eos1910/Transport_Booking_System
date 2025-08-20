#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

#include "Transport.h"
#include <iostream>

using namespace std;

class Car : public Land {
    public:
        Car(string i, int p, double c) : Land(i, "Car", p, c) {}
};

class Lorry : public Land {
    public:
        Lorry(string i, int p, double c) : Land(i, "Lorry", p, c) {}
};

class Boat : public Water {
    public:
        Boat(string i, int p, double c) : Water(i, "Boat", p, c) {}
};

class Ship : public Water {
    public:
        Ship(string i, int p, double c) : Water(i, "Ship", p, c) {}
};

class Plane : public Air {
    public:
        Plane(string i, int p, double c) : Air(i, "Plane", p, c) {}
};

class Helicopter : public Air {
    public:
        Helicopter(string i, int p, double c) : Air(i, "Helicopter", p, c) {}
};

#endif // OPTIONS_H_INCLUDED