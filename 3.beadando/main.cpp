#include <iostream>
#include <cmath>

using namespace std;


// csináljunk egy osztályt, aminek az egyes függvényei az integrálás meg deriválás
// pontosabban  - ívhossz szerinti integrál
//              - Richardson-extrapoláció , O(h^6) rendű közelítés
//              - középpontos-módszer
//              - trapéz-módszer
//              - 1/3 Simpson szabály , 1% pontosság



// AZ ÍVHOSSZ SZERINTI INTEGRÁL: integrate(a,b)  (1 + f'^2)^(1/2)  ds





//HÁZIBAN MEGADOTT FGV
double func (double x , const int F , const double q , const int a , const int h) //itt már használom h-t mint földtől mért távolság
{
    return ((F/q) * (cosh((q*x)/F)) - cosh((q*a)/(2*F)) + h);
}

//INTEGRÁLOKHOZ KELL EGYENLŐ LÉPÉSKÖZ
double middle ( int x, int x1,int n) // itt az x kezdőérték szerepébe bújik, onnan számolva 
{
    double m[1];
    for (int i = 0; i < n + 1; i++)
    {
        double something; // ideiglenes vált. eltárolt számolás
        something = [(x - x1) / 2] + i*(x - x1) ; //
        m.push_back(something);     // hozzáfűz egy elemet a lista végéhez
    }
    return m;
}


//RICHARDSON EXTRAPOLÁCIÓ 6. RENDŰ KÖZELÍTÉS
template <typename T>
double Richardson_ex(int x, double dx, T f)
{
    double ff;
    ff = (5*f(x + 4*dx , ) - 200*f(x + 2*dx) + 1280*f(x + dx) - 1280*f(x - dx) + 200*f(x - 2*dx) -5*f(x - 4*dx));
    return ff;
}

//IDE JÖHET MAJD AZ ÍVHOSSZ INTEGRÁL

// NEWTON-COTES FORMULA
double Newton_Cotes(T f, int m, int n)
{
    double M;
    double step = [m[1] - m[0]];
    for (int i = 0; i < n; i++)
    {
        M += f(m[i]) * step;
    }
    return M;
}

//TRAPÉZOS GÖRBE ALATTI TERÜLET
double trapezoidal(T f, int m, const int n)
{
    // ugyanaz mint a Newton_Cotes csak le kell vonni f(x0) / 2 és f(xn) / 2 a végén
    double MM;
    double step = [m[1] - m[0]];
    for (int i = 0; i < n; i++)
    {
        MM += f(m[i]) * step;
    }
    MM = MM - [f(m[0]) / 2] - [f(m[n-1]) / 2];
    return MM;
}

