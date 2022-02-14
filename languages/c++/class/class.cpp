#include <iostream>
using std::cout;
using std::endl;
/*
clear;g++ -std=c++2a class.cpp && ./a.exe
*/

class Base_0 {
    public:
        int x;
        Base_0() {
            cout << "base_0 constructor" << endl;
        }

         ~Base_0() {
            cout << "destructor of Base_0" << endl;
        }

        void display(){
            this->x = 200;
            cout << "base " << this->x << endl;
        }
};

class Base {
    public:
        int x;
        static int s;
        Base(int param_x): x {param_x}  {
            Base::s = 200;
            cout << "base constructor" << endl;
        }
        virtual ~Base(){
            cout << "destructor of Base" << endl;
        }
        void display(){
            this->x = 200;
            cout << "base " << this->x << endl;
        }
        virtual void display1(){            
            cout << "virtual display1 " << endl;
        }
};

/* Constructors of base classes are called in the order in which they are mentioned 
in during class creation. i.e, they are not called in the order  how they are mentioned
in the derived constructor function.

*/
class Derived final : public Base_0, public Base {
    public:
        static int s;
        int x;
        int y;
        explicit Derived(int x1) : Base(99), Base_0() {
            cout << "Derived constructor" << x1 << endl;
        }
        ~Derived(){
            cout << "destructor of Derived" << endl;
        }
        void display(){
            //this->x = 100;
            cout << __FUNCTION__ << " : in derived class but base x:= " << this->Base::x << ", " << Base::s << endl;
        }
        virtual void display1(){            
            cout << "over ridden base virtual display1 " << endl;
        }
        void add(int x, int y) { }
};


int Base::s;
int Derived::s = 100;
int main() {    
    Base *pb = new Derived(4);  
    delete pb;
    Derived d(1);
    d.display1();
    Derived::display1(&d);
    return 0;
}
