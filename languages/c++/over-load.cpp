#include<iostream>
using namespace std;

/*
g++ over-load.cpp  && ./a.exe
*/

/*
functions are not over loaded based on return type.
since the argument type or numbers are differntiating 
factors, so, there must be one such thing.
Else, a compilation error would occur.
ex: in below, instead of double a, if we had int a
we get compile err even when return type is different
for both the following functions. 
reason is - compiler thinks, both functions are same
on initial passes... return type does not matter much at this moment.

*/
double fun(double a) {
    std::cout << "hi double " << a << std::endl;    
    return 0.0;
}

int fun(int a) {
    std::cout << "hi int " << a << std::endl;
    return 0;
}

class A {
    public:
        int number;
        /* constructor */
        A(int n){
            number = n;
        }
        int operator+(A n) {
            std::cout << "a1 " << this->number << " a2: " << n.number;
            return this->number + n.number;
        }

};


int main(int argc, char *argv[]) {
    
    fun(4);
    fun(5.06);
    /* operator overloading */
    A n1(4), n2(8);

    int x = n1 + n2;    
    x = n1.operator+(n2);
    std::cout << " fffff: " << x;
    return 0;
}