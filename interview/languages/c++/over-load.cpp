#include<iostream>
using namespace std;

/*
g++ over-load.cpp  && ./a.exe
*/

double fun(double a) {
    cout << "hi double " << a << endl;    
    return 0.0;
}

int fun(int a) {
    cout << "hi int " << a << endl;
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
            cout << "a1 " << this->number << " a2: " << n.number;
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
    cout << " fffff: " << x;
    return 0;
}