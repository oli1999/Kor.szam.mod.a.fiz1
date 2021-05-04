#define _USE_MATH_DEFINES

#include "3DMatrixclass.h"


using namespace std;




int main()
{
    Matrix<float> A(3);
    Matrix<float> B(3);
    Matrix<float> C(3);
    ifstream fin("input.txt"); 
    //fin >> A;
    //cout << "This is A : " << endl << A << endl;
    //fin >> B;
    //cout << "This is B : " << endl << B << endl;

    double pi = M_PI;
    double x_angle_in_degree , y_angle_in_degree , z_angle_in_degree;
    double x_angle_in_radians , y_angle_in_radians , z_angle_in_radians;
  


    cout << "Gimme your rotation angle(in degree) on x axis : " << endl;
    cin >> x_angle_in_degree;
    cout << "Your angle(in degree) on x axis is: " << endl << x_angle_in_degree << endl;
    x_angle_in_radians = x_angle_in_degree * (pi / 180);
    cout << "Your angle(in radians) on x axis is: " << endl << x_angle_in_radians << endl;


    cout << "Gimme your rotation angle(in degree) on y axis : " << endl;
    cin >> y_angle_in_degree;
    cout << "Your angle(in degree) on y axis is: " << endl << y_angle_in_degree << endl;
    y_angle_in_radians = y_angle_in_degree * (pi / 180);
    cout << "Your angle(in radians) on y axis is: " << endl << y_angle_in_radians << endl;

    cout << "Gimme your rotation angle(in degree) on z axis : " << endl;
    cin >> z_angle_in_degree;
    cout << "Your angle(in degree) on z axis is: " << endl << z_angle_in_degree << endl;
    z_angle_in_radians = z_angle_in_degree * (pi / 180);
    cout << "Your angle(in radians) on z axis is: " << endl << z_angle_in_radians << endl;

    
    
    A.rotx(x_angle_in_radians);
    B.roty(y_angle_in_radians);
    C.rotz(z_angle_in_radians);

    cout << "This is the rotation matrix on x axis: " << endl << A << endl;
    cout << "This is the rotation matrix on y axis: " << endl << B << endl;
    cout << "This is the rotation matrix on z axis: " << endl << C << endl;



    fin.close();
    return 0;
}