#include <iostream>
#include <cmath>
#include "radians.h"
#include "degrees.h"


void f(Degrees deg);
int main()
{
    /*Degrees Deg1 (atan2(5,6));
    f(Degrees(180));
    Radians Rad1 = M_PI / 4;
    auto Deg2 = Deg1 + Rad1;
    bool A = Deg2 > Rad1;
    Deg2.print();
    Deg1.print();
    Rad1.print();
    std::cout << A << std::endl;*/

    Degrees Deg1 = Degrees(180.0);
    Radians Rad1 = Radians(2 * M_PI);
    Degrees Deg2 = Deg1 + Rad1;
    Radians Rad2 = Deg1 + Rad1;
    Radians rad3 = Rad2 * 3;
    //rad3.print();
    Degrees deg3 = Deg2 * 3;
    //rad3.print();
    //deg3.print();
    Degrees Deg4 = Deg2 / 2;
    //Deg4.print();
    Degrees Deg5 = 2 * Deg1;
    //Deg5.print();
    Radians Rad4 = 2 * Rad1;
    Rad4 = Rad1 * 3;
    //Rad4.print();
    Deg5 += Degrees(1);
    Deg5 /= Degrees(1);
    Deg5.print(); 
    rad3 *= Rad1;
    rad3.print();
    Deg1 *= 2;
    Rad1 /= 5;
    Deg1.print();
    Rad1.print();
    return 0;
}
