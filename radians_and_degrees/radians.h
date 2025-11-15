#pragma once
#include <iostream>
#include <cmath>
#include "degrees.h"

class Degrees;

class Radians 
{
    public:
    double rad;
    explicit Radians(double a_rad)
    {
        rad = a_rad;
    }

    Radians operator+ (Radians b);
    Radians operator- (Radians b);
    Radians operator* (Radians b);
    Radians operator* (double a);
    Radians operator/ (double a);
    Radians operator/ (Radians b);
    bool operator> (Radians b);
    bool operator< (Radians b);

    void operator+= (Radians b);
    void operator-= (Radians b);
    void operator*= (Radians b);
    void operator/= (Radians b);

    void operator*= (double a);
    void operator/= (double a);
    

    void print();
    friend Radians operator* (double a, Radians b);
    operator Degrees();
};

Radians operator* (double a, Radians b);
