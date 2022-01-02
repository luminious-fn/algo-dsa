/*
Implementing a smart pointer for generic type with reference count.
This is RAII - Resource Aquasition Is Initialization.
Managing heap objects using stack (scoped) objects.
Memory gets cleared automatically when
stack object goes out of scope. (less leaky!)
This is a redimentory garbage collector!!!

https://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c

*/

#include <iostream>
//using namespace std;

class RefCount {
    private:
        int ref_count;
    public:
        explicit RefCount(void);
        void inc_count(void);
        int dec_count(void);
        void display_count(void) const;
};

RefCount::RefCount(): ref_count {0} {
};
void RefCount::inc_count(void) {
    ref_count++;
};
int RefCount::dec_count(void){
    //display_count();
    return --ref_count;
};
void RefCount::display_count(void) const {
    std::cout << "ref_count = " << ref_count << std::endl;
};

template <typename T>
class smart_pointer {
    private:
        T *ptr;
        RefCount *ref_count { new (std::nothrow) RefCount {} };
    public:
        explicit smart_pointer (T *ptr);
        ~smart_pointer();
        T& operator* (void) const;                        
        T* operator->(void) const;            
        smart_pointer<T>& operator= (smart_pointer<T> &right_side);        
};

template <typename T>
smart_pointer<T>& smart_pointer<T>::operator= (smart_pointer<T> &right_side) {
    std::cout << "= operator " << std::endl;
    right_side.ref_count->display_count();
    if (!this->ref_count->dec_count()){
        std::cout << " = delete smart ptr object " << std::endl;
        delete this->ptr;
        delete this->ref_count;
    }
    this->ptr = right_side.ptr;
    this->ref_count = right_side.ref_count;
    this->ref_count->inc_count();
    return *this;
};

template <typename T>
smart_pointer<T>::smart_pointer (T *ptr):ptr { ptr } {            
    std::cout << "constructor called" << std::endl;
    ref_count->inc_count();            
};

template <typename T>
smart_pointer<T>::~smart_pointer(){
    std::cout << "destructor called" << std::endl;    
    if(!ref_count->dec_count()) {
        if(ptr) {
            std::cout << " destructor: delete smart ptr object " << std::endl;
            delete this->ptr;
            delete this->ref_count;
        }
    }
};

template <typename T>
T& smart_pointer<T>::operator* (void) const {
    std::cout << "* operator called" << std::endl;
    return *ptr;
};                

template<typename T>
T* smart_pointer<T>::operator->(void) const {
            std::cout << "-> operator called" << std::endl;
            return ptr;
};

class Shape {    
    public:
        int val;
        void display(void) const;

};
void Shape::display(void) const {
            std::cout << "display" << std::endl;
};

int main(int argc, char *argv[]){

    /* smart pointer */
    smart_pointer<Shape> sm_ptr { new (std::nothrow) Shape };        
    sm_ptr->val = 999;
    (*sm_ptr).val = 1000;
    sm_ptr->display();
    smart_pointer<Shape> sm_ptr1 { new (std::nothrow) Shape };
    sm_ptr1 = sm_ptr;

    std::cout << "-------------------" << std::endl;    
    return 0;
}
