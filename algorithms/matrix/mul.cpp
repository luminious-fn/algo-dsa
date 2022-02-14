/*
clear; g++ matrix-multiplication.cpp  && ./a.exe
*/

#include<iostream>
#include<array>
using namespace std;

/*
a := m X n
b := n X q
c := m X q
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
template<typename T, size_t row, size_t col>
void print_matrix(std::array<std::array<T, col>, row> & arr) {
    cout << endl << " print std::array" << endl;
    for (auto row1 : arr){
        for(auto col1: row1 ){
            std::cout << col1 << " ";
        }
        std::cout << endl;
    }
}


template<typename T, size_t r1, size_t c1, size_t r2, size_t c2 >
void mm(std::array<std::array<T, c1>, r1> & a, 
        std::array<std::array<T, c2>, r2> & b,
        std::array<std::array<T, c2>, r1> & result){
    
    for(int i = 0; i < a.size(); i++){
        for(int j=0; j<b[0].size(); j++){
            for(int k=0; k<a[0].size(); k++){
                result[i][j] += a[i][k] * b[k][j];                
            }
        }
    }
    return;
}


int main(int argc, char *argv[]) {
    multiply(a, b, c, 2, 3, 2);
    print_matrix(c, 2, 3);

    std::array<std::array<int, 3>, 2> a {
        {   
            {1, 2, 3}, 
            {4, 5, 6}            
        }
    };
    std::array<std::array<int, 2>, 3> b {
        {   
            {7, 8}, 
            {9, 10},
            {11, 12}
        }
    };
    std::array<std::array<int, 2>, 2> c {
        {   
            {0, 0}, 
            {0, 0},            
        }
    };    
    mm(a, b, c);
    print_matrix(c);
}