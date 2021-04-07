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




#include <iostream>
#include <cmath>
#include "vector.h"
using namespace std;



int main() 
{
    Vector2d<double> v = {17.0 , 2.0};                                                // def. and value giving
    Vector2d<double> u = {4.0 , -2.0};                                                // def. and value giving
    std::cout << "v vector: " << v.x << " " << v.y << endl;                                        
    std::cout << "u vector: "<< u.x << " " << u.y << endl;                                         
    auto q = v + u;                                                // sima összeadás
    std::cout << "q vector: "<< q.x << " " << q.y << endl;                                          
    auto r = u + v;                                               //fordított sorrendű összeadás
    std::cout << "r vector: "<< r.x << " " << r.y << endl;                                         
    v += u;                                                       // összeadás és értékadás
    std::cout << "v vector: "<< v.x << " " << v.y << endl;                                             
    std::cout << "u vector: "<< u.x << " " << u.y << endl;                                               
    Vector2d<double> v2 = {17.0 , 2.0};                                                // def. and value giving
    Vector2d<double> u2 = {4.0 , 2.0};                                                // def. and value giving
    std::cout << "v2 vector: "<< v2.x << " " << v2.y << endl;                                             
    std::cout << "u2 vector: "<< u2.x << " " << u2.y << endl; 
    v2 -= u2;                                                       // kivonás és értékadás
    std::cout << "v2 vector: "<< v2.x << " " << v2.y << endl;                                             
    std::cout << "u2 vector: "<< u2.x << " " << u2.y << endl;                                                                                        
    double constans = 5.0;
    auto c_u2 = constans * u2;                                      // skalárral való szorzás
    std::cout << "c_u2 vector: "<< c_u2.x << " " << c_u2.y << endl;
    auto k = length_of_vec(u2);                                     // vektor hossza
    std::cout << "k vector: "<< k.x  << endl;                                         
    auto ww = v2 - u2;                                              // sima kivonás                 
    std::cout << "ww vector: "<< ww.x << " " << ww.y << endl; 
    Vector2d<double> v3 = {10.0 , 20.0};                                                // def. and value giving
    Vector2d<double> u3 = {15.0 , 25.0};                                                // def. and value giving
    auto www = dot_product(v3 , u3);                                // skaláris szorzás
    std::cout << "ww vector: "<< www << endl; 
    v3 *= constans;
    std::cout << "v3 vector: "<< v3.x << " " << v3.y << endl;


    return 0;
}