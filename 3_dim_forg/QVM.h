template <typename T>       // T template a 4 elemű "lénynek" definiáljuk
struct quat 
{

    T a[4];               // új típust adunk meg , ez lesz a quaternion

    template <class R>    // R template 
    operator R() const    // overloadolunk egy operátort R, azért hogy eltudja végezni a számunkra szükséges műveletet
    {
    R r;
    assign(r,*this);    // ez a művelet pedig az,hogy r-nek beadja *this-el hivatkozva a[4] elemeit?
    return r;           // visszaadja r-t modosítva az előzőek szerint
    }

};


template <class Quaternion>
struct quat_traits;


template <class T>
struct quat_traits< quat<T> > 
{

    typedef T scalar_type;      // 

    template <int I>
    static scalar_type read_element( quat<T> const & x ) 
    {
    return x.a[I];
    }

    template <int I>
    static scalar_type & write_element( quat<T> & x ) 
    {
        return x.a[I];
    }

};