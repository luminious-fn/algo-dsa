#include<iostream>
using namespace std;

/*
clear; g++ -std=c++2a poly-morphism.cpp  && ./a.exe

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

class base {
	public:
	base() {
		cout << "base constructor" << endl;
	}
	virtual void fun(void) const = 0; // Pure virtual
	virtual void fun_virt(void) const;
	virtual void fun_pure_virt(void) const = 0; // Enforces the implementation
};

void base::fun_virt(void) const {
    cout << "in base: fun_virt" << endl;
}

class derived : public base {
    public:
	derived(){
		cout << "derived: constructor" << endl;
	}
	void fun(void) const override;
	void fun(int x) {

	}
	void fun_virt(void) const override {
		cout << "in derived : fun_virt" << endl;
	}
	void fun_pure_virt(void) const override {
		cout << "implementing the pure virtual class in derived" << endl;
	}
};

void derived::fun(void) const {
    cout << "in derived" << endl;
}


int main(int argc, char *argv[]) {

    derived der;
    cout << "-----------";
    base *ptr_base;
    ptr_base = &der;
    der.fun();
    cout<< "d fun \n";
    ptr_base->fun();

    der.fun_virt();
    ptr_base->fun_virt();

    ptr_base->fun_pure_virt();

    cout << endl;
    return 0;
}
