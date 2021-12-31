#include <iostream>
#include <memory>
using namespace std;
 /*
clear;g++ circular-ref.cpp  && ./a.exe
*/

// Forward declare class B
class B;
 
class A{
    public:
        int a;
        //std::shared_ptr<B> ptr;
        std::weak_ptr<B> ptr;
        A(int value = 200) { a = value; }
        ~A() {std::cout << "Destructor for A\n"; }
};
 
class B{
    public:
        int a;
        //std::shared_ptr<A> ptr;
        std::weak_ptr<A> ptr;
        B(int value = 200) { a = value; }
        ~B() {std::cout << "Destructor for B\n"; }
};
 
int main() {
    {
    std::shared_ptr<A> ptr_a = std::make_shared<A>(750);
    std::shared_ptr<B> ptr_b = std::make_shared<B>(750);
     
    // Make ptr_a point to ptr_b
    ptr_a->ptr = ptr_b;
    // And make ptr_b point to ptr_a
    ptr_b->ptr = ptr_a;
    }
    std::cout << "done all" << endl;
 
    return 0;
}