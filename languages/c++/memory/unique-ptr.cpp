#include <iostream>
#include <memory>
/*
https://thispointer.com/c11-unique_ptr-tutorial-and-examples/
*/
class Shape {    
    public:
        int val;        
        explicit Shape(int val): val {val} {            
        };

        void display(void) const {
            std::cout << "val: " << val << std::endl;
        }
};

void demo_pass1(std::unique_ptr<Shape> &uptr){
    std::cout << __FUNCTION__ << " start" << std::endl;
    uptr->display();    
    std::cout << __FUNCTION__ << " end" << std::endl;
}

std::unique_ptr<Shape> demo_pass2(std::unique_ptr<Shape> uptr){
    std::cout << __FUNCTION__ << " start" << std::endl;
    uptr->display();    
    std::cout << __FUNCTION__ << " end" << std::endl;
    return uptr;    
}

int main(int argc, char *argv[]){
    
    //std::unique_ptr<Shape> uptr1 {new (std::nothrow) Shape { 100 } };
    std::unique_ptr<int> uptr1_int { std::make_unique<int>(10) };
    std::unique_ptr<Shape> uptr1 { std::make_unique<Shape>(100) };
    if (uptr1) {
        std::cout << "uptr1 is Good !!!" << std::endl;
        uptr1->display();
    } else {
        std::cout << "uptr1 is null!!!" << std::endl;
    }
    // uptr2 = uptr1; Not supported, gives compilation err
    std::unique_ptr<Shape> uptr2;
    uptr2 = std::move(uptr1);
    /* passing unique pointer by reference. Here we should not use move.
    since ref is an alias, uptr2 is still valid/
    */
    demo_pass1(uptr2);
    uptr2->display();

    /* pass by value. so, we have to use move. it becomes invalid, so one
    has to return it back, if want to use it further.

    */
    uptr2 = demo_pass2(std::move(uptr2));
    if (uptr2) {
        std::cout << "if: after moving " << std::endl;
        uptr2->display();
    } else {
        std::cout << "else: after moving " << std::endl;
    }
    

    /*check if unique_ptr uptr1 is still managing the resource.
    Now, it is not... it is a safety check.
    */
    if (uptr1) { 
        uptr1->display();
    } else {
        std::cout << "uptr1 is no more managed !" << std::endl;
    }
    return 0;
}