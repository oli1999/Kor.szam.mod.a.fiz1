#include <iostream>
#include<vector>

using namespace std;

double derival(double const& y)
{
    return 1 + pow(y,2);
}

template <typename F>
std::vector<double> Euler_method(double const& h , double const& y0 , int const& number_of_steps , F const& f)
{
    std::vector<double> result;
    double y;
    result.push_back(y0);
    for (int i = 1; i < number_of_steps; i++)
    {
        y = result.back();
        result.push_back(y + h * f(y));
    }
    return result;
}

template <typename State, typename T, typename RHS, typename Callback>
auto solve_rk4(State y0, T t0, T t1, T h, RHS f, Callback cb)
{
    T t = t0;
    State y = y0;
    while(t < t1)
    {
        if(t + h > t1)
        { 
            h = t1 - t;
        }
    State k1 = f(t, y);
    State k2 = f(t + h * (T)0.5, y + (h * (T)0.5) * k1);
    State k3 = f(t + h * (T)0.5, y + (h * (T)0.5) * k2);
    State k4 = f(t + h, y + h * k3);
    y = y + (k1 + k4 + (T)2 * (k2 + k3)) * (h / (T)6);
    t = t + h; cb(t, y);
    }
    return y;
}

int main()
{
    std::vector<double> a;
    int h , y0 , number_of_steps ;
    h = 200;
    y0 = 0;
    number_of_steps = 1000;
    a = Euler_method(h,y0,number_of_steps,derival);
    for (int i = 1; i < 2; i++)
    {
        cout << "This is the result: " << a[i] << endl;
    }
return 0;
}