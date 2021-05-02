#define _USE_MATH_DEFINES

#include "3DMatrixclass.h"
#include <cmath>
#include<vector>
#include <algorithm>

using namespace std;




int main()
{
    Matrix<int> A(3);
    Matrix<int> B(3,1);
    ifstream fin("input.txt"); 
    //fin >> A;
    //cout << "This is A : " << endl << A << endl;
    //fin >> B;
    //cout << "This is B : " << endl << B << endl;

    double pi = M_PI;
    int angle_in_degree;

    cout << "Gimme your angle(in degree) bitch : " << endl;
    cin >> angle_in_degree;
    cout << "You gave me your angle , you're a good lad! " << endl << "Your angle is: " << endl << angle_in_degree << endl;

    float angle_in_radians;
    angle_in_radians = angle_in_degree * (pi / 180);
    cout << "Your angle(in radians) is: " << endl << angle_in_radians << endl;

    float sinuszalas;
    sinuszalas = sin(angle_in_radians);
    cout << "Sine of your angle(in radians) : " << endl << sinuszalas << endl;

    cout << "Gimme your A(3,3) Matrix bitch : " << endl;
    cin >> A;
    cout << "This is A : " << endl << A << endl;
    //cout << "Gimme your B(3,1) Matrix bitch : " << endl;
    //cin >> B;
    //cout << "This is B : " << endl << B << endl;
    //cout << "A * B : " << endl << (A * B) << endl;


    // ADJUK MEG EGY SZÁMOT AMI A FORGATÁS FOKJA , AZT A BEOLVASÁSKOR KONVERTÁLJUK ÁT ELŐSZÖR RADIÁNBA, AZTÁN SIN,COS FÜGGVÉNYEKKEL,AHOGY NEKÜNK KELL



    fin.close();
    return 0;
}