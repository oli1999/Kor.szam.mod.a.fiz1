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
    // multiplication a's right side
    Vector2d<T>& operator*= (Vector2d<T> const& v , double alfa) //this is dif. from * op. 'cause, this is not just a multiplication but also value giving at the same time
                                        // that's why we have to initialize it inside the structure
    {
        x = alfa * v.x ; y = alfa * v.y;
        return *this; // return value points at the original objects
    }
    // multiplication a's left side
    Vector2d<T>& operator*= (Vector2d<T> const& v) //this is dif. from * op. 'cause, this is not just a multiplication but also value giving at the same time
                                        // that's why we have to initialize it inside the structure
    {
        x *= v.x ; y *= v.y;
        return *this; // return value points at the original objects
    }

    // substraction and value giving
    Vector2d<T>& operator-= (Vector2d<T> const& v) //this is dif. from * op. 'cause, this is not just a multiplication but also value giving at the same time
                                        // that's why we have to initialize it inside the structure
    {
        // magic happens here
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
Vector2d<SM> operator* (Vector2d<SM> const& a , Vector2d<SM> const& alfa)
{
    return Vector2d<SM>{alfa * a.x , alfa * a.y}; // It gives back vectors 2 comp. multi. with the same scalar
};

template <typename SU>      // substraction
Vector2d<SU> operator- (Vector2d<SU> const& a , Vector2d<SU> const& b)
{
    return Vector2d<SU>{ a.x - b.x ,  a.y - b.y}; 
};

template <typename NO>      // normalization
Vector2d<>  (Vector2d<> const& a , Vector2d<> const& b)
{
    return Vector2d<>{}; 
};

template <typename LE>      // length
Vector2d<>  (Vector2d<> const& a , Vector2d<> const& b)
{
    return Vector2d<>{}; 
};