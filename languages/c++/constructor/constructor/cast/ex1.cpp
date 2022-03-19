#include<iostream>
#include<string>
using namespace std;

/*
g++ ex1.cpp  && ./a.exe
*/

class A{};
class B{};
class C:public A, public B{};

int main()
{
    C d;
    A *a = &d;
    B *b = &d;

    bool bool1 = reinterpret_cast<char*>(a) == reinterpret_cast<char*>(&d);
    bool bool2 = b == &d;
    bool bool3 = reinterpret_cast<char*>(a) == reinterpret_cast<char*>(b);

    std::cout << bool1 << bool2 << bool3 << std::endl; // 110

    return 0;
}