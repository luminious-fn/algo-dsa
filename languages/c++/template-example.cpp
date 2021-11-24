#include<iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

/*
g++ template-example.cpp  && ./a.exe
*/

template <typename T1, typename T2>
void fun(T1 data1, T2 data2) {
    cout << " input data1/2: " << data1  << " and  " << data2 << endl;
}

template <class T1, typename T2>
class MyClass {
    public:
        T1 data1;
        T2 data2;
        void dump() {
            cout << data1 << " " << data2 << endl;
        }
};

int main(int argc, char *argv[]) {
    
    MyClass<int, float> aa;
    aa.data1 = 44;
    aa.data2 = 33.22;

    aa.dump();

    
    fun(44, 87.99);
    fun("Om Tat Sat", 879);
    cout << endl;
    return 0;
}