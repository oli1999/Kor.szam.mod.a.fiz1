#include <iostream>
using namespace std;

template <typename T>
struct Vector2d // definition of a struct, attention! it's not a class
{
    T x,y; // give some variables, in this case these are the coordinates
                // of the 2 dim vector
    Vector2d<T>& operator+=(Vector2d<T> const& v) //this is dif. from + op. 'cause
                // this is not just a sum but also value giving at the same time
                // this is why we have to initialize it inside the structure
    {
        x += v.x; y += v.y;
        return *this; // visszatérési érték rámutat ez eredeti objektumunkra
    }
};

template <typename N>
Vector2d<N> operator+ (Vector2d<N> const& a, Vector2d<N> const& b) // definition of the sum operation
                // when you call this sum you have to give it 2 vec with 2 comp.
                // in the definition only the binary loc. was given to the def.
                // 'cause if it is a 100 dim instead of two you would run out of ram
{
    return Vector2d<N>{a.x + b.x , a.y + b.y}; // this will give you back the sum of the
                                           // 2 vector's comp. separated
};



int main() 
{
    std::cout << "Sanyi a kiraly" << endl;
    std::cout << "Johet a masodik beadando" << endl;
    
    Vector2d<double> v = {17.0 , 2.0}; // v is a componens of the Vector2D structure
                              // we can also initialies it with {} and some number
                              // in this case only 2 number should have pass to the struct
                              // 'cause we made only 2 variables
                              // the order of the var. is important
    //v.x = 5.0; // this line overwrite the 1.0 to 5.0
    Vector2d<double> u = {4.0 , -2.0};
    auto w = v + u;         // the sum operator got a new meaning, now we can use it for vec.comp.
    auto www = u + v;       // it can sum in translate order too
    // it's not working for multiplication, I have to 
    //auto ww = v += u;     // attention! this sum and value giv. is changing the originial value of v vec.
    std::cout << v.x << " " << v.y << endl;
    std::cout << u.x << " " << u.y << endl;
    std::cout << w.x << " " << w.y << endl;
    //std::cout << ww.x << " " << ww.y << endl;
    std::cout << www.x << " " << www.y << endl;
    return 0;
}