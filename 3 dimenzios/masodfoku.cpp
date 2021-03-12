#include <iostream>

int main(int,char**)
{
    auto masodfoku(double a,double b,double c)
    {
        double discriminant = b*b -4*a*c;
        double real_or_not = sqrt(discriminant);
        y1 = (-b + real_or_not) / 2*a;
        y2 = (-b - real_or_not) / 2*a;
        return y1 , y2;
    }

    return 0;
}