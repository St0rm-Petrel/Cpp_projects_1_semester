#include <iostream>
#include <cmath>
#include "radians.h"
#include "degrees.h"

Radians Radians::operator+(Radians b) 
{
    return Radians(rad + b.rad);
}

Radians Radians::operator-(Radians b) 
{
    return Radians(rad - b.rad);
}

Radians Radians::operator*(Radians b) 
{
    return Radians(rad * b.rad);
}

Radians Radians::operator/(Radians b) 
{
    if (b.rad == 0)
    {
        throw std::runtime_error("Dividing by zero");
    }
    else
    {
        return Radians(rad / b.rad);
    }
}

bool Radians::operator<(Radians b) 
{
    return bool(rad < b.rad);
}

bool Radians::operator>(Radians b) 
{
    return bool(rad > b.rad);
}

Radians::operator Degrees() 
{
    return Degrees(rad * (180.0 / M_PI));
}

Radians Radians:: operator* (double a)
{
    return Radians(rad * a);
}

Radians Radians:: operator/ (double a)
{
   if (a == 0)
    {
        throw std::runtime_error("Dividing by zero");
    }
    else
    {
        return Radians(rad / a);
    }
}

Radians operator* (double a, Radians b)
{
    return Radians(a * b.rad);
}

void Radians::operator+= (Radians b)
{
    rad = rad + b.rad;
}

void Radians::operator-= (Radians b)
{
    rad = rad - b.rad;
}

void Radians::operator*= (Radians b)
{
    rad = rad * b.rad;
}

void Radians::operator/= (Radians b)
{
        if (b.rad == 0)
    {
        throw std::runtime_error("Dividing by zero");
    }
    else
    {
        rad = rad / b.rad;
    }
}

void Radians::operator*= (double a)
{
    rad = a * rad;
}
void Radians::operator/= (double a)
{
    if (a == 0)
    {
        throw std::runtime_error("Dividing by zero");
    }
    else
    {
        rad = rad / a;
    }
}

void Radians:: print()
{
    std::cout << rad << std::endl;
}

