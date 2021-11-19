/*
clear; g++ matrix-multiplication.cpp  && ./a.exe
*/

#include<iostream>
using namespace std;
/*
a := m X n
b := p X q
c := m X q, where n ==  p, always
*/

int a[2][2] = {
    {1, 2},
    {3, 4}
};
int b[2][3] = {
    {5, 6, 7},
    {8, 9, 10}
}; 

int c[2][3];

void multiply(int a[2][2], int b[2][3], int c[2][3], int row, int col, int row_size) {    
    int i, j, k;    
    for(i=0; i < row; i++ ){
        for(j=0; j < col; j++){
            for (k=0; k < row_size; k++){
                c[i][j] += a[i][k] * b[k][j];
                cout << a[i][k] << " " << b[k][j] << " " << c[i][j] << " ";
                cout << endl;
            }
            cout << "over " << endl;
            cout << c[i][j] << " ";
        }
    }
}

void print_matrix(int a[2][3], int row, int col) {
    cout << endl << " print" << endl;
    for (int i=0; i < row; i++){
        for(int j=0; j < col; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[]) {

    multiply(a, b, c, 2, 3, 2);
    print_matrix(c, 2, 3);
}