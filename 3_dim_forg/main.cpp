#define _USE_MATH_DEFINES

#include "3DMatrixclass.h"
#include <cmath>

using namespace std;




int main()
{
    Matrix<int> A(3);
    Matrix<int> B(3);

    ifstream fin("input.txt"); 

    fin >> A;
    //cout << "This is A : " << endl << A << endl;
    fin >> B;
    //cout << "This is B : " << endl << B << endl;
    double pi = M_PI;
    cout << pi << endl;
    int angle_in_degree;
    cout << "Gimme your angle(in degree) bitch : " << endl;
    cin >> angle_in_degree;
    cout << "You gave me your angle , you're a good lad! " << endl << "Your angle is: " << endl << angle_in_degree << endl;
    float angle_in_radians;
    angle_in_radians = angle_in_degree * (pi / 180);
    cout << "Your angle(in radians) is: " << endl << angle_in_radians << endl;
    float result;
    result = sin(angle_in_radians);
    cout << "Sine of your angle(in radians) : " << endl << result << endl;
    Matrix<int> AA(2);
    cout << "Gimme your matrix(2*2) bitch : " << endl;
    cin >> AA;
    cout << "You gave me your matrix , you're a good lad! " << endl << "Your matrix is: " << endl << AA << endl;



    fin.close();
    return 0;
}