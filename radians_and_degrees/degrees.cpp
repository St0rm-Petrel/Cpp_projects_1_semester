#include <iostream>
#include <cmath>
#include "radians.h"
#include "degrees.h"


Degrees Degrees::operator+(Degrees b) 
{
    return Degrees(deg + b.deg);
}

Degrees Degrees::operator-(Degrees b) 
{
    return Degrees(deg - b.deg);
}

Degrees Degrees::operator*(Degrees b) 
{
    return Degrees(deg * b.deg);
}

Degrees Degrees::operator/(Degrees b) 
{
    if (b.deg == 0)
    {
        throw std::runtime_error("Dividing by zero");
    }
    else
    {
        return Degrees(deg / b.deg);
    }
}

bool Degrees::operator<(Degrees b) 
{
    return bool(deg < b.deg);
}

bool Degrees::operator>(Degrees b) 
{
    return bool(deg > b.deg);
}

Degrees::operator Radians()
{
    return Radians(deg * (M_PI / 180.0));
}


Degrees Degrees:: operator* (double a)
    {
        return Degrees(deg * a);
    }

Degrees Degrees:: operator/ (double a)
{
    if (a == 0)
    {
        throw std::runtime_error("Dividing by zero");
    }
    else
    {
        return Degrees(deg / a);
    }
}

Degrees operator* (double a, Degrees b)
{
   return Degrees(a * b.deg); 
}

void Degrees::operator+= (Degrees b)
{
    *this = *this + b;
}

void Degrees::operator-= (Degrees b)
{
    deg = deg - b.deg;
}
void Degrees::operator*= (Degrees b)
{
    deg = deg * b.deg;
}
void Degrees::operator/= (Degrees b)
{
        if (b.deg == 0)
    {
        throw std::runtime_error("Dividing by zero");
    }
    else
    {
        deg = deg / b.deg;
    }
}

void Degrees::operator*= (double a)
{
    deg = a * deg;
}
void Degrees::operator/= (double a)
{
    if (a == 0)
    {
        throw std::runtime_error("Dividing by zero");
    }
    else
    {
        deg = deg / a;
    }
}

void Degrees:: print()
{
    std::cout << deg << std::endl;
}

