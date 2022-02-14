#include<cstdlib>
#include<iostream>
using std::cout;
using std::endl;

/*
g++ mod1.cpp && ./a.exe 
*/
int main(int argc, char *argv[]){
    int m=7, n=2;
    cout << m%n << endl; // output: 1
    cout << (m/float(n)) << endl; // output: 1
    cout << (m/n)*n + (m%n); /* this gives output = 5, 
                             but in python, same gives 6.
    */
   /*
    From c++ primer book
   The modulus operator is defined so that if m and n are integers and n is nonzero,
then (m/n)*n + m%n is equal to m. 
   */
  return EXIT_SUCCESS;
}