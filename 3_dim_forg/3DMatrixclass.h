#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include<vector>
#include <algorithm>

using namespace std;

/*
DOCUMENTATION

Ez a mátrix osztály tud:
                    - at fügvénnyel a mátrix egyes értékei meghívhatóak
                    - sorokat is oszlopokat beolvasni
                    - pointert használ a mátrix helyére mutatáshoz
                    - tetszőleges méretű mátrixxal tud dolgozni
                    - ha végzett a műveletekkel akkor törli a mátrix memórai helyét
                    - egy mátrix értékét képes átadni az osztály egy mások object-ének
                    - megvizsgálja, hogy az osztály 2 object-e egyenlő-e
                    - megvizsgálja, hogy az osztály 2 object-e  NEM egyenlő-e
                    - beolvas a terminálból
                    - kiír a terminálba
                    - beolvas .txt fájlból
                    - kiír .txt fájlba
                    - rotx a x tengely körüli forgásmátrix van definiálva a konzolból bekért szöggel
                    - roty a y tengely körüli forgásmátrix van definiálva a konzolból bekért szöggel
                    - rotz a z tengely körüli forgásmátrix van definiálva a konzolból bekért szöggel
*/


template <class T>
class Matrix
{
public:

    int rows,cols;
    T* pMatrix;

    Matrix(int Rows, int Cols)
    {
        rows = Rows;
        cols = Cols;

        pMatrix = new T[rows * cols];
    }

    Matrix(int Size)
    {
        rows = Size;
        cols = Size;

        pMatrix = new T[rows * cols];
    }

    Matrix(const Matrix& matrix)
    {
        rows = matrix.rows;
        cols = matrix.cols;

        pMatrix = new T[rows * cols];

        for (int i = 0; i < rows * cols; i++)
        {
            pMatrix[i] = matrix.pMatrix[i];
        }
        
    }

    ~Matrix()
    {
        delete[] pMatrix;
    }

    

    Matrix& operator= (const Matrix& matrix)
    {
        this->~Matrix();

        rows = matrix.rows;
        cols = matrix.cols;
        
        pMatrix = new T[rows *cols];

        for (int i = 0; i < rows * cols; i++)
        {
            pMatrix[i] = matrix.pMatrix[i];
        }
        return *this;
    }

    bool operator== (const Matrix& matrix)
    {
        if (rows == matrix.rows && cols == matrix.cols)
        {
            for (int i = 0; i < rows *cols; i++)
            {
                if (pMatrix[i] != matrix.pMatrix[i])
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!= (const Matrix& matrix)
    {
        return 1 - (*this == matrix);
    }

    Matrix operator+ (const Matrix& matrix)
    {
        if (rows == matrix.rows && cols == matrix.cols)
        {
            Matrix result(rows, cols);

            for (int i = 0; i < rows * cols; i++)
            {
                result.pMatrix[i] = pMatrix[i] + matrix.pMatrix[i];
            }

            return result;
        }
    }

    Matrix operator- (const Matrix& matrix)
    {
        if (rows == matrix.rows && cols == matrix.cols)
        {
            Matrix result(rows, cols);

            for (int i = 0; i < rows * cols; i++)
            {
                result.pMatrix[i] = pMatrix[i] - matrix.pMatrix[i];
            }

            return result;
        }
    }

    Matrix operator* (const Matrix& matrix)
    {
        if (cols == matrix.rows)
        {
            Matrix result(rows,matrix.cols);

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < matrix.cols; j++)
                {
                    result.pMatrix[i * result.cols + j] = 0;
                    for (int k = 0; k < cols; k++)
                    {
                        result.pMatrix[i * result.cols + j] += pMatrix[i * cols + k] * matrix.pMatrix[k * matrix.cols + j];
                    }
                }
            }
            return result;
        }
    }

    T& at(int x, int y)
    {
        return pMatrix[x - 1 + rows*(y - 1)];
    }


    void rotx(double angle)
    {
        this->at(1,1) = 1;
        this->at(1,2) = 0;
        this->at(1,3) = 0;
        this->at(2,1) = 0;
        this->at(2,2) = cos(angle);
        this->at(2,3) = -sin(angle);
        this->at(3,1) = 0;
        this->at(3,2) = sin(angle);
        this->at(3,3) = cos(angle);
    }

    void roty(double angle)
    {
        this->at(1,1) = cos(angle);
        this->at(1,2) = 0;
        this->at(1,3) = sin(angle);
        this->at(2,1) = 0;
        this->at(2,2) = 1;
        this->at(2,3) = 0;
        this->at(3,1) = -sin(angle);
        this->at(3,2) = 0;
        this->at(3,3) = cos(angle);
    }

    void rotz(double angle)
    {
        this->at(1,1) = cos(angle);
        this->at(1,2) = -sin(angle);
        this->at(1,3) = 0;
        this->at(2,1) = sin(angle);
        this->at(2,2) = cos(angle);
        this->at(2,3) = 0;
        this->at(3,1) = 0;
        this->at(3,2) = 0;
        this->at(3,3) = 1;
    }

    
    void rot_vec(double angle , Matrix& u)
    {
        this->at(1,1) = 1 + (1/2 + 1/2 * cos(angle)) * (-pow(u.at(1,3),2) -pow(u.at(1,2),2));
        this->at(1,2) = -u.at(1,3) * sin(angle) + (1/2 + 1/2 * cos(angle) * u.at(1,2) * u.at(1,3));
        this->at(1,3) = u.at(1,2) * sin(angle) + (1/2 + 1/2 * cos(angle) * u.at(1,3) * u.at(1,1));
        this->at(2,1) = u.at(1,3) * sin(angle) + (1/2 + 1/2 * cos(angle) * u.at(1,1) * u.at(1,2));
        this->at(2,2) = 1 + (1/2 + 1/2 * cos(angle)) * (-pow(u.at(1,3),2) -pow(u.at(1,1),2));
        this->at(2,3) = -u.at(1,1) * sin(angle) + (1/2 + 1/2 * cos(angle) * u.at(1,3) * u.at(1,2));
        this->at(3,1) = -u.at(1,2) * sin(angle) + (1/2 + 1/2 * cos(angle) * u.at(1,1) * u.at(1,3));
        this->at(3,2) = u.at(1,1) * sin(angle) + (1/2 + 1/2 * cos(angle) * u.at(1,2) * u.at(1,3));
        this->at(3,3) = 1 + (1/2 + 1/2 * cos(angle)) * (-pow(u.at(1,2),2) -pow(u.at(1,1),2));
    }
    
    

    friend istream& operator>> <> (istream& s, Matrix& matrix);
    friend ostream& operator<< <> (ostream& s, const Matrix& matrix);

    friend ifstream& operator>> <> (ifstream& fs, Matrix& matrix);
    friend ofstream& operator<< <> (ofstream& fs, const Matrix& matrix);
}; 




template <typename T>
istream& operator>> (istream& s, Matrix<T>& matrix)
{
    for (int i = 0; i < matrix.rows *matrix.cols; i++)
    {
        s >> matrix.pMatrix[i];
        
    }
    return s;
}

template <typename T>
ostream& operator<< <> (ostream& s, const Matrix<T>& matrix)
{
    for (int i = 0; i < matrix.rows ; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            s << matrix.pMatrix[i * matrix.cols + j] <<" ";
        }
        s << endl;
    }
    return s;
}

template <typename T>
ifstream& operator>> (ifstream& fs, Matrix<T>& matrix)
{
    for (int i = 0; i < matrix.rows * matrix.cols; i++)
    {
        fs >> matrix.pMatrix[i];
    }
    return fs;
}

template <typename T>
ofstream& operator<< <> (ofstream& fs, const Matrix<T>& matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; i++)
        {
            fs << matrix.pMatrix[i * matrix.cols + j] << " ";
        }
        fs << endl;
    }
    return fs;
}

//class Complex
//{
//private:
//    float a, b, c, d;
//}