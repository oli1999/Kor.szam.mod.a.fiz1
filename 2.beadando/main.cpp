// KÉRDÉSEK

// 1. Külön headerbe készítsük el?
// Válasz: vector.h külön fájl, az egész osztály berakva oda # include "vector.h" hívom meg
// 2. Ennyi elég?
// double type a skalárral való szorzás, 
// 3. Amikor a szorzás operátort definiálom jobbról,balról akkor az "operator*" kifejezést nem tudom többször használni.
//              Bármilyen nevet adhatok az operátornak? Vagy muszály úgy kezdődnie, hogy "operator" és utána valami más szót is írhatok.
//              Például "operator*_left" a másik "operator*_right"
// 4. Struct tamplate-nél mindegy hány műv. def. a struct-ba eleég egy template?
// Válasz: igen
// 5. Lehet ugyanazt a nevet adni a fgv.-nek úgy,hogy mást definiálunk rajta?
// Válasz: Igen, itt nem igaz a C-beni szabály, hogy mindegyik műveletnek más nevet kell adni, csak az argumentumnak kell másnak lennie és lehet ugyanaz a név.



// összeadás, értékadásösszeadás, skalárral való szorzás, kivonás, vektorok skaláris szorzata, normalizáció, vektorok hossza
// vektorok skaláris szorzása ne legyen operator* jel, skalárral való szorzás legyen operator*
#include <iostream>
using namespace std;

template <typename T>
struct Vector2d // definition of a struct, attention! it's not a class
{
    T x,y; // give some variables, in this case these are the coordinates
                // of the 2 dim vector

    // sum and value giving
    Vector2d<T>& operator+= (Vector2d<T> const& v) //this is dif. from + op. 'cause ,this is not just a sum but also value giving at the same time
                // that's why we have to initialize it inside the structure
    {
        x += v.x; y += v.y;
        return *this; // return value points at the original objects
    }
    // multiplication with scalar v's left side
    Vector2d<T>& operator*= (Vector2d<T> const& v , const double alfa) //this is dif. from * op. 'cause, this is not just a multiplication but also value giving at the same time
                                        // that's why we have to initialize it inside the structure
    {
        x = alfa * v.x ; y = alfa * v.y;
        return *this; // return value points at the original objects
    }
    // multiplication with scalar v's right side
    Vector2d<T>& operator*= (Vector2d<T> const& v) //this is dif. from * op. 'cause, this is not just a multiplication but also value giving at the same time
                                        // that's why we have to initialize it inside the structure
    {
        x = v.x * alfa ; y = v.y * alfa;
        return *this; // return value points at the original objects
    }
};

template <typename S>
Vector2d<S> operator+ (Vector2d<S> const& a, Vector2d<S> const& b) // definition of the sum operation
                // when you call this sum you have to give it 2 vec with 2 comp.
                // in the definition only the binary loc. was given to the def.
                // 'cause if it is a 100 dim instead of two you would run out of ram
{
    return Vector2d<S>{a.x + b.x , a.y + b.y}; // this will give you back the sum of the
                                           // 2 vector's comp. separated
};

template <typename M>   // multiplication a's right side
Vector2d<M> operator* (Vector2d<M> const& a, Vector2d<M> const& b) 
{
    return Vector2d<M>{a.x * b.x , a.y * b.y}; 
};

template <typename MM>      // multiplication a's left side
Vector2d<MM> operator* (Vector2d<MM> const& a, Vector2d<MM> const& b)
{
    return Vector2d<MM>{b.x * a.x , b.y * a.y};
};

template <typename SM>      // multiplication with scalar
Vector2d<SM> operator* (Vector2d<SM> const& a , Vector2d<SM> double alfa)
{
    return Vector2d<SM>{alfa * a.x , alfa * a.y}; // It gives back vectors 2 comp. multi. with the same scalar
};









int main() 
{
    Vector2d<double> v = {17.0 , 2.0}; // def. and value giving
    Vector2d<double> u = {4.0 , -2.0}; // def. and value giving
    auto w = v * u;                     
    std::cout << v.x << " " << v.y << endl;
    std::cout << u.x << " " << u.y << endl;
    std::cout << w.x << " " << w.y << endl;
    auto p = u * v;
    std::cout << p.x << " " << p.y << endl;
    return 0;
}