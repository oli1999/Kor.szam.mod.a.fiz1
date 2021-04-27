#include "3DMatrixclass.h"
#include <cmath>

using namespace std;




int main()
{
    Matrix<int> A(3);
    Matrix<int> B(3);

    ifstream fin("input.txt"); 

    fin >> A;
    cout << "This is A : " << endl << A << endl;
    fin >> B;
    cout << "This is B : " << endl << B << endl;

    cout << "This is A + B : " << endl << (A + B) << endl;
    cout << "This is A - B : " << endl << (A - B) << endl;

    Matrix<float> C(2);
    cin >> C;
    cout << "This is C : " << endl << C << endl;

    fin.close();
    return 0;
}