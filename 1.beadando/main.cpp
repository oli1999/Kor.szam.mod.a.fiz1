#include <iostream>
#include<cmath>

using namespace std;

// here I need some template, for 2 function
// template azt csinálja hogy bármilyen 
template<typename F> F fgv(F x){return x*x;} // ez a fgv
template<typename D> D fgv_d(D x){return 2*x;} // ez a fgv deriváltja
template<typename V, typename S, typename S2> V newton_method(V x,V x2, V epsilon ,S f1 , S2 f2);

int main() 
{
    float x , x2 , epsilon ;                       // egy random függvény érintőjének meredeksége (x1,f(x1)) pont és (x2,0 pont) között f fgv deriváltja
    cout << "Kerem x1,x2 es epsilon erteket." << endl;
    cin >> x >> x2 >> epsilon ;
    float b = newton_method<float>(14,20,12,fgv<double>,fgv_d<double>);
    cout <<  "Eredmeny: " << b << endl;
    return 0;
}

template<typename V , typename S , typename S2> V newton_method(V x,V x2, V epsilon ,S f1 ,S2 f2) 
{
    V x1 = x - f1(x) / f2(x);                      // ez a sor azért kell h while el tudja kezdeni az összehasonlítást
    while (abs(x1-x2) >= epsilon)                   //epsilon mondja meg mikor vagyunk elég közel már zérushelyhez
    {
        x = x1;
        x1 = x - f1(x) / f2(x);                               // x2 = (x - fgv(x)) / fgv_d(x) ezt jelenti ez asor csak röviditve
    }
    return x2;
} 