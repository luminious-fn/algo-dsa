#include<iostream>
using namespace std;

/*
g++ poly-morphism.cpp  && ./a.exe
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
    p->fun();

    c.fun_virt();
    p->fun_virt();

    p->fun_pure_virt();

    cout << endl;
    return 0;
}