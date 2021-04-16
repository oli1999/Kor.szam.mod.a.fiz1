template <typename T>
class arc_length
{
public:
    T x;
    T h;
    T f;


    rich_ex_h4(f,x,h) 
    {
        return ((- f(x + 2*h) + [8 * f(x + h)] - [8 * f(x - h)] + f(x - 2*h)) / (12*h)) ;
    }
};
