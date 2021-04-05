#include <iostream>
#define N 4
using namespace std;

  

void rotateMatrix(int mat[N][N]) // "in-place" : kiválasztó algoritmus, ami csak annyi memóriát használ amennyi az adat tárolására kell; óramutató járásával ellentétes irányba forgatja el az N * N-es mátrixot 90 fokkal
{   /* 1. N oldalú mátrixban N/2 db kört kell kialakítani, hogy elforgathassuk a mátrix elemeket.
       2. Első for loop  körökön(2 van) megy végig . Ezért van, hogy 3*3 mátrixra csak úgy működik, hogy ki van pótolva a 4*4-es mátrix 0-kal.
       3. Második for loop annyiszor fut le amennyiszer kell elemeket cserélnie.

    */
    
    for (int x = 0; x < N / 2; x++)                         // megcsinálja a külső majd a belső kör cseréjét
    {
        
        for (int y = x; y < N - x - 1; y++)                 // ahányszor lefut a ciklus annyiszor 4 elemet cserél ki a külső körben
        {
            int temp = mat[x][y];                           // egy ideiglenes változóban eltároljuk az első sor első elemét
            mat[x][y] = mat[y][N - 1 - x];                  // 1.sor 1.elem helyére 1.sor 4.eleme ezek a számok változnak a for ciklus előre haladtával
            mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];  // 1.sor 4.elem helyére 4.sor 4.eleme ezek a számok változnak a for ciklus előre haladtával
            mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];  // 4.sor 4.elem helyére 4.sor 1.eleme ezek a számok változnak a for ciklus előre haladtával
            mat[N - 1 - y][x] = temp;                       // 4.sor 1.elem helyére 1.sor 1.eleme ezek a számok változnak a for ciklus előre haladtával
        }
    }
}
  

void displayMatrix(int mat[N][N]) // kiíratjuk a mátrixot dupla forciklussal
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
        {
            cout  << mat[i][j] << " "; // először 1.sor 1. eleme, aztán 1.sor 2.eleme, aztán 1.sor 3.eleme...
                                       // ha végig ér az első soron akkor van vége a belső for ciklusnak utána vált a külső forciklus egyet és megint a belső fut le N-szer...
        }
        cout << endl; // minden kiírt sor után új sort kezd
    }
}
  

int main()
{
    
    int mat[N][N] = 
    {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    
    rotateMatrix(mat); // elforgatás végrehajtása a tényleges próba mátrixon
    displayMatrix(mat); // az elforgatás után a mátrix kiírása
  
    return 0;
}