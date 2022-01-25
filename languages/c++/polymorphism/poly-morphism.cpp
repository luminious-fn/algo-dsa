#include<iostream>
using namespace std;

/*
g++ poly-morphism.cpp  && ./a.exe

1. compile time polymorphism
    a. function over loading in a class: same function name and same return type
        but different number or type of arguments.
        note: having two functions with same name but with different return type is an ERROR
    b. Assume there is a function in base class. however, we want to redefine it in 
    derived class. Here we will keep the 
    same function name, 
    same return type, 
    same argument list (in number, in order, in type)  as in the base class only.
    Such re-defintion in base class is called function over-riding.
    It is like suppressing the base class function.
    In this case, during compile time, we can surely know which function gets called.
    a base pointer type will always call base function even if it is pointing to drivered class.
    a derived pointer will always call derived function since it can only point to derived class.
    
2. run time poly-morphism using virtual and function overriding
    this is done by fuction over riding.
    a. define a fucntion in bases class as virtual, then redefine it in derived class.
        then, if we call it with base class pointer, the function that gets called is 
        - if pointer is pointing to base class, it calls base function
        - if pointer is pointing to derived class, it calls derived class function
    b. tis is achieved only through base class pointer. typically, we write genric code using
    base class pointer, but we can pass all types of derived class pointer to it.

*/

double fun(double a) {
    cout << "hi double " << a << endl;
    return 0.0;
}

int fun(int a) {
    cout << "hi int " << a << endl;
    return 0;
}

class parent {
    public:
#if 0 
    void fun(void) {
        cout << "in parent" << endl;
    }
#else
        virtual void fun(void) = 0;
#endif
        virtual void fun_virt(void) {
            cout << "in parent: fun_virt" << endl;
        }
        virtual void fun_pure_virt(void) = 0; // Enforces the implimentation
};

class child : public parent {
    public:
        void fun(void) {
            cout << "in child" << endl;
        }
        void fun(int x) {

        }

        void megha(int x) {

        }


        void fun_virt(void) {
            cout << "in child : fun_virt" << endl;
        }
        void fun_pure_virt(void) {
            cout << "implementing the pure virtual class in child" << endl;
        }
};

int main(int argc, char *argv[]) {

    child c;
    //parent virtual_class; This can't be done since it is abstract class
    parent *p;
    p = &c;
    c.fun();
    cout<< "d fun \n";
    p->fun();
    //p->megha(1);
    //c.megha(1);

    c.fun_virt();
    p->fun_virt();

    p->fun_pure_virt();

    cout << endl;
    return 0;
}
