#include<iostream>

using namespace std;
/*
  g++ new-op.cpp && ./a.exe
 * */

#define index(x,y) (x*3+y)

class Box{
    public:
        int x;
        Box(int a);
        //Box();
};

Box::Box(int a){
    cout << "1 arg constructor called" << endl;
    x = 100;
}
/*
Box::Box(){
    cout << "no arg constructor called" << endl;
    x = 100;
}*/


int main(int argc, char *argv[]){

    int *p = new int;
    int **pp_1 = new int *;
    int **pp_2 = new int *[10];
    pp_2[1] = new int[5];
    pp_2[1] = new int;
    
    
    double* pvalue  = NULL;      // Pointer initialized with null 
    pvalue  = new double [3 * 4];  // Allocate memory for a 3x4 array
    pvalue[index(2,3)] = 999;
    cout << "val: " << pvalue[index(2,3)] << endl;
    delete [] pvalue;

    //double** pvalue1  = NULL;      // Pointer initialized with null 
    //pvalue1  = new double [3][4];  // Allocate memory for a 3x4 array 
   
    Box *pb = new Box[5] { Box(99), Box(99), Box(99), Box(99) };
    /* Following fails because, new operator expects a zero arg constructor.
     * typically, this is defined by compiler but since i defined my own constructor,
     * here, it does not get defined. hence new does not find it. hence error.
     * if you uncomment above zero arg constructor, it works.
     */
    Box *pb_zero_arg = new Box[2];
    //Box obj[2] = { Box(1) };

 }
