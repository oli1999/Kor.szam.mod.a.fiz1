#include <iostream>
#include <cmath>
#include <vector>

using namespace std;



//HÁZIBAN MEGADOTT FGV
double func (double x , int F , double q , int a , int h) //itt már használom h-t mint földtől mért távolság
{
    return ((F/q) * (cosh((q*x)/F)) - cosh((q*a)/(2*F)) + h);
}

//INTEGRÁLOKHOZ KELL EGYENLŐ LÉPÉSKÖZ
std::vector<double> middle ( double x, double x1,int n) // itt az x kezdőérték szerepébe bújik, onnan számolva , n mennyire sűrűen
{
    std::vector<double> m;
    for (int i = 0; i < n; i++)
    {
        double something; // ideiglenes vált. eltárolt számolás
        something = ((x1 - x) / 2) + i*(x1 - x) ; //
        m.push_back(something);     // hozzáfűz egy elemet a lista végéhez
    }
    return m;
}


//RICHARDSON EXTRAPOLÁCIÓ 6. RENDŰ KÖZELÍTÉS
template <typename T>
double Richardson_ex(double x, double dx, T f,  int F , double q , int a , int h)
{
    return (5*f(x + 4*dx , F , q , a , h ) - 200*f(x + 2*dx , F , q , a , h) + 1280*f(x + dx , F , q , a , h) - 1280*f(x - dx , F , q , a , h) + 200*f(x - 2*dx , F , q , a , h) -5*f(x - 4*dx , F , q , a , h) / (8 * dx));
}



// NEWTON-COTES FORMULA
double Newton_Cotes( std::vector<double> m, int n) // f - lesz ívhossz,
{
    double M = 0;
    double step = (m[1] - m[0]); // mindig állandó
    for (int i = 0; i < n; i++)
    {
        M += sqrt((1 + pow(Richardson_ex(m[i] , step , func , 900 , 1.8 , 200 , 35), 2))) * step;
    }
    return M;
}

//TRAPÉZOS GÖRBE ALATTI TERÜLET
double trapezoidal( double start, double step, int n) // ugyanaz mint a Newton_Cotes csak le kell vonni f(x0) / 2 és f(xn) / 2 a végén
{
    double MM = 0;
    for (int i = 0; i < n; i++)
    {
        MM += sqrt((1 + pow(Richardson_ex(start + step*i , step , func , 900 , 1.8 , 200 , 35),2))) * step;
    }
    MM = MM - ( sqrt((1 + pow(Richardson_ex(start , step , func , 900 , 1.8 , 200 , 35),2))) * step/ 2) - (sqrt((1 + pow(Richardson_ex(start + step*(n-1) , step , func , 900 , 1.8 , 200 , 35),2))) * step / 2);
    return MM;
}


int main()
{
    
    
    std::cout << Newton_Cotes(middle(-100, -99.9 , 2000) , 2000) << endl;
    std::cout << trapezoidal(-100 , 1 , 200) << endl;

    return 0;
}
