//#include <iostream>
//#include <arc_length.h>
//using namespace std;
//#include <cmath>

// csináljunk egy osztályt, aminek az egyes függvényei az integrálás meg deriválás
// pontosabban  - ívhossz szerinti integrál
//              - Richardson-extrapoláció , O(h^6) rendű közelítés
//              - középpontos-módszer
//              - trapéz-módszer
//              - 1/3 Simpson szabály , 1% pontosság



// AZ ÍVHOSSZ SZERINTI INTEGRÁL: integrate(a,b)  (1 + f'^2)^(1/2)  ds

template <typename T>
double Richardson_ex(int x, double dx, T f, const int F, const double q, const int a, const int h)
{
    return (5*f(x + 4*dx , ) - 200*f(x + 2*dx) + 1280*f(x + dx) - 1280*f(x - dx) + 200*f(x - 2*dx) -5*f(x - 4*dx));
}


double Newton_Cotes(T f, double dx, const int n)
{
    double M;
    for (int i = 0; i < n; i++)
    {
        M += f(m[i]) * dx;
    }
    
}

double trapezoidal(T f, double dx, const int n)
{
    // ugyanaz mint a Newton_Cotes csak le kell vonni f(x0) / 2 és f(xn) / 2 a végén
}



double func (double x , const int F , const double q , const int a , const int h)
{
    return ((F/q) * (cosh((q*x)/F) - cosh((q*a)/(2*F)) + h);
}

double middle ( int x, int x1, const int n ) // itt az x kezdőérték szerepébe bújik, onnan számolva 
{
    double m[n];
    for (int i = 0; i < n + 1; i++)
    {
        double something;
        something = [(x - x1) / 2] + i*(x - x1) ;
        m.push_back(something)
    }
    return m;
}








