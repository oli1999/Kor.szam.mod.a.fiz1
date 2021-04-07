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
    auto q = v + u;
    std::cout << "q vector: "<< q.x << " " << q.y << endl;                                          
    auto r = u + v;
    std::cout << "r vector: "<< r.x << " " << r.y << endl;                                         
    v += u;
    std::cout << "v vector: "<< v.x << " " << v.y << endl;                                             
    std::cout << "u vector: "<< u.x << " " << u.y << endl;                                               
    Vector2d<double> v2 = {17.0 , 2.0};                                                // def. and value giving
    Vector2d<double> u2 = {4.0 , 2.0};                                                // def. and value giving
    std::cout << "v2 vector: "<< v2.x << " " << v2.y << endl;                                             
    std::cout << "u2 vector: "<< u2.x << " " << u2.y << endl; 
    v2 -= u2;
    std::cout << "v2 vector: "<< v2.x << " " << v2.y << endl;                                             
    std::cout << "u2 vector: "<< u2.x << " " << u2.y << endl;                                             
    //auto w = v2 * u2;                     
    //std::cout << "w vector: "<< w.x << " " << w.y << endl;                                             
    double constans = 5.0;
    auto c_u2 = constans * u2;
    std::cout << "c_u2 vector: "<< c_u2.x << " " << c_u2.y << endl;
    auto k = length_of_vec(u2);
    std::cout << "k vector: "<< k.x << " " << k.y << endl;                                         // I'm not sure, this is the task, but it's workin'
    auto ww = v2 - u2;                                                               
    std::cout << "ww vector: "<< ww.x << " " << ww.y << endl; 

    return 0;
}