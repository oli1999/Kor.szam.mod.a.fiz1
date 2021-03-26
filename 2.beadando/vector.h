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


//multiplication
template <typename M>   
Vector2d<M> operator* (Vector2d<M> const& a, Vector2d<M> const& b) 
{
    return Vector2d<M>{a.x * b.x , a.y * b.y};                                          // this mult. the 2 vector's x and y comp. with eachother
};

// multiplication2
//template <typename MM>      
//Vector2d<MM> operator* (Vector2d<MM> const& a, Vector2d<MM> const& b)
//{
//    return Vector2d<MM>{b.x * a.x , b.y * a.y};
//};

// multiplication with scalar
//template <typename SM>      
//Vector2d<SM> operator* (Vector2d<SM> const& a , const double alfa)
//{
//    return Vector2d<SM>{alfa * a.x , alfa * a.y};                               // It gives back vectors 2 comp. multi. with the same scalar
//};

//length
template <typename L>   
Vector2d<L> length_of_vec (Vector2d<L> const& a)                                
{
    return Vector2d<L>{sqrt(a.x * a.x + a.y * a.y)};                            // add the vectors 2 comp. square, and after that it takes the square root of the sum
};