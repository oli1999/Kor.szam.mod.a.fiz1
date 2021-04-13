template <typename T>
struct Vector2d                                                             // definition of a struct, attention! it's not a class
{
    T x,y;                                                                  // give some variables, in this case these are the coordinates of the 2 dim vector

    // sum and value giving
    Vector2d<T>& operator+= (Vector2d<T> const& v)                          //this is dif. from + op. 'cause ,this is not just a sum but also value giving at the same time
                                                                            // that's why we have to initialize it inside the structure
    {
        x += v.x; y += v.y;
        return *this;                                                       // return value points at the original objects
    }

    // substraction and value giving
    Vector2d<T>& operator-= (Vector2d<T> const& v)                          //this is dif. from - op. 'cause ,this is not just a substraction but also value giving at the same time
                                                                            // that's why we have to initialize it inside the structure
    {
        x -= v.x; y -= v.y;
        return *this;                                                       // return value points at the original objects
    }

    // multiplication with scalar and value giving
    Vector2d<T>& operator*= ( T alfa)                                      //this is dif. from * op. 'cause ,this is not just a  multiplication with scalar but also value giving at the same time
                                                                            // that's why we have to initialize it inside the structure
    {
        
        x *= alfa ; y *= alfa ;
        return *this;                                                       // return value points at the original objects
    }
    
};

// addition
template <typename S>
Vector2d<S> operator+ (Vector2d<S> const& a, Vector2d<S> const& b)          // when you call this sum you have to give it 2 vec with 2 comp. in the definition only the binary loc. was given to the def.
                                                                            // 'cause if it is a 100 dim instead of two you would run out of ram
{
    return Vector2d<S>{a.x + b.x , a.y + b.y};                             // this will give you back the sum of the 2 vector's comp. separated
};

// substraction
template <typename SS>
Vector2d<SS> operator- (Vector2d<SS> const& a, Vector2d<SS> const& b)          // when you call this sub you have to give it 2 vec with 2 comp. in the definition only the binary loc. was given to the def.
                                                                            // 'cause if it is a 100 dim instead of two you would run out of ram
{
    return Vector2d<SS>{a.x - b.x , a.y - b.y};                             // this will give you back the substraction of the 2 vector's comp. separated
};


//dot product
template <typename DM>   
DM dot_product (Vector2d<DM> const& a, Vector2d<DM> const& b) 
{
    return  (a.x * b.x) + (a.y * b.y) ;                                          // this mult. the 2 vector's x and y comp. with eachother
};



// multiplication with scalar
template <typename SM>      
Vector2d<SM> operator* (const double alfa , Vector2d<SM> const& a)
{
    return Vector2d<SM>{alfa * a.x , alfa * a.y};                               // It gives back vectors 2 comp. multi. with the same scalar
};



//length
template <typename L>   
Vector2d<L> length_of_vec (Vector2d<L> const& a)                                
{
    return Vector2d<L>{sqrt(a.x * a.x + a.y * a.y)};                            // add the vectors 2 comp. square, and after that it takes the square root of the sum
};

//cin
//template <typename CIN>   
//Vector2d<CIN> vec_cin (Vector2d<CIN> const& a)                                
//{
//    return Vector2d<CIN> cin << a.x << a.y ;                            // add the vectors 2 comp. square, and after that it takes the square root of the sum
//};