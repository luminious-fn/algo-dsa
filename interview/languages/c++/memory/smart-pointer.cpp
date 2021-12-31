/*
Implementing a smart pointer for int type.
Managing heap objects using stack (scoped) objects.
Memory gets cleared automatically when
stack object goes out of scope. (less leaky!)
This is a redimentory garbage collector!!!
*/

#include <iostream>
using namespace std;

class smart_pointer {
    private:
    public:
        int *&ptr; 
        smart_pointer(int *&ptr):ptr(ptr){            
            cout << "constructor called" << endl;            
        };
        
        void reinit(int *ptr){            
            cout << "constructor called" << endl;            
        };

        ~smart_pointer(){
            cout << "destructor called" << endl;
            delete ptr;
        };

        int & operator*(){
            cout << "deref operator called" << endl;
            return *ptr;
        }
};

int main(int argc, char *argv[]){

    int *raw_ptr = new (nothrow) int;
    if(raw_ptr == nullptr){
        cout << "memory allocation failed";
        exit(1);
    }

    /* smart pointer */
    smart_pointer my_sp(raw_ptr);        
    *my_sp = 999;
    cout << *my_sp << endl;    
    return 0;
}

