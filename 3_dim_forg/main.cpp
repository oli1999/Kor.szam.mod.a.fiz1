#define _USE_MATH_DEFINES

#include "3DMatrixclass.h"


using namespace std;




int main()
{
    Matrix<float> X(3);
    Matrix<float> Y(3);
    Matrix<float> Z(3);
    Matrix<float> W(3);
    //std::vector<float> u(3);
    Matrix<float> u(3,1);
    

    
    double pi = M_PI;
    double x_angle_in_degree , y_angle_in_degree , z_angle_in_degree;
    double x_angle_in_radians , y_angle_in_radians , z_angle_in_radians;
  


    cout << "Gimme your rotation angle(in degree) on x axis : " << endl;
    cin >> x_angle_in_degree;
    cout << "Your angle(in degree) on x axis is: " << endl << x_angle_in_degree << endl;
    x_angle_in_radians = x_angle_in_degree * (pi / 180);
    cout << "Your angle(in radians) on x axis is: " << endl << x_angle_in_radians << endl << endl;

    cout << "Gimme your rotation angle(in degree) on y axis : " << endl;
    cin >> y_angle_in_degree;
    cout << "Your angle(in degree) on y axis is: " << endl << y_angle_in_degree << endl;
    y_angle_in_radians = y_angle_in_degree * (pi / 180);
    cout << "Your angle(in radians) on y axis is: " << endl << y_angle_in_radians << endl << endl;

    cout << "Gimme your rotation angle(in degree) on z axis : " << endl;
    cin >> z_angle_in_degree;
    cout << "Your angle(in degree) on z axis is: " << endl << z_angle_in_degree << endl;
    z_angle_in_radians = z_angle_in_degree * (pi / 180);
    cout << "Your angle(in radians) on z axis is: " << endl << z_angle_in_radians << endl << endl;

    
    
    X.rotx(x_angle_in_radians);
    Y.roty(y_angle_in_radians);
    Z.rotz(z_angle_in_radians);



    cout << "This is the rotation matrix on x axis: " << endl << X << endl;
    cout << "This is the rotation matrix on y axis: " << endl << Y << endl;
    cout << "This is the rotation matrix on z axis: " << endl << Z << endl;
    //cout << "This is the rotation matrix on x,y axis: " << endl << (X * Y) << endl;
    // MÁTRIXOK ÖSSZESZORZÁSÁNÁL a(1,3) a(2,3) a(3,1) és a(3,2) NEM JÓ AZ ELŐJELE 45°használtam x és y rot-nál is,30°-nál is ugyanígy az előjelek rosszak ,sima egészszám mátrixokkal tesztelve nincs gond
    

    cout << "Gimme your 3D vector : " << endl;
    std::cin >> u;
    std::cout << "Your 3D vector is: " << endl << u << endl;


    W.rot_vec(x_angle_in_degree,u);
    cout << "This is the rotation matrix around u vector: " << endl << W << endl;



    return 0;
}