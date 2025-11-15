#pragma once
#include <iostream>
#include <cmath>
#include "radians.h"

class Radians;

class Degrees 
{
    public:
    double deg;
    explicit Degrees(double a_deg)
    {
        deg = a_deg;
    }

    Degrees operator+ (Degrees b);
    Degrees operator- (Degrees b);
    Degrees operator* (Degrees b);
    Degrees operator/ (Degrees b);
    Degrees operator* (double a);
    Degrees operator/ (double a);
    bool operator> (Degrees b);
    bool operator< (Degrees b);
    void print();
    friend Degrees operator* (double a, Degrees b);
    
    void operator+= (Degrees b);
    void operator-= (Degrees b);
    void operator*= (Degrees b);
    void operator/= (Degrees b);
    
    void operator*= (double a);
    void operator/= (double a);
    

    operator Radians(); 

};
    Degrees operator* (double a, Degrees b);
