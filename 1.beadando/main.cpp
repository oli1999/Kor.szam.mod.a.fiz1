#include <iostream>
#include<math.h>

using namespace std;

// here I need some template, for 2 function
// template azt csinálja hogy bármilyen 
template<typename F> F fgv(F x){return x*x;} // ez a fgv
template<typename D> D fgv_d(D x){return 2*x;} // ez a fgv deriváltja
template<typename V, typename S> N newton_method(N x,N x2, N epsilon ,S f1 , S f2);

int main() 
{
    float x , x2 , epsilon , dif;                       // egy random függvény érintőjének meredeksége (x1,f(x1)) pont és (x2,0 pont) között f fgv deriváltja
    cout << "Kérem x1,x2 es epsilon erteket." << endl;
    cin >> x >> x2 >> epsilon ;
    float b = newton_method<float>(14,20,12,fgv,fgv_d);
    return 0;
}

template<typename N> N newton_method(N x,N x2, N epsilon ,S f1 ,S f2) 
{
    dif = fgv(x) / fgv_d(x);                      // ez a sor azért kell h while el tudja kezdeni az összehasonlítást
    while (abs(dif) >= epsilon)                   //epsilon mondja meg mikor vagyunk elég közel már zérushelyhez
    {
        dif = fgv(x) / fgv_d(x);
        x2 = x2 - dif;                               // x2 = (x - fgv(x)) / fgv_d(x) ezt jelenti ez asor csak röviditve
    }
    return x2;
} 