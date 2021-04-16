#include <iostream>
#include <arc_length.h>
using namespace std;

// csináljunk egy osztályt, aminek az egyes függvényei az integrálás meg deriválás
// pontosabban  - ívhossz szerinti integrál
//              - Richardson-extrapoláció , O(h^6) rendű közelítés
//              - középpontos-módszer
//              - trapéz-módszer
//              - 1/3 Simpson szabály , 1% pontosság



int main() 
{

}




#include <iostream>
#include <cmath>
#include <iomanip>		// Needed too manipulate the display
using namespace std;



// the function
long double f(long double x)
{
    long double f;
    f=sin(x);
    return f;
}



// The Derivative function
void Derivative(long double x, int n, long double h, long double D[10][10])
{
    int i, j;
    for (i=0; i<n; i++)
    {
        D[i][0]=(f(x+h)-f(x-h))/(2*h);
        for (j=0; j<=(i-1); j++)
        {
            D[i][j+1]=D[i][j]+(D[i][j]-D[i-1][j])/(pow(4.0,double(j+1))-1);
        }
        h=h/2;
    }
}



int main(int argc, char *argv[])

{
    long double D[10][10];
    int n=10, digits=5;
    long double h=1, x=0;

    Derivative(x, n, h, D);

    // Set a fixed amount of digits to show
    cout.setf(ios::fixed );
    cout.setf(ios::showpoint);
    cout <<  setprecision(digits) << endl;

    // Printout the diagram
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<i+1;j++)
        {
            cout << setw(digits+2) << D[i][j] << " ";
        }
        cout << endl;
    }

    // Unset the fixed point

    cout.unsetf(ios::fixed);
    cout.unsetf(ios::showpoint);
    system("PAUSE");
    return 0;

}