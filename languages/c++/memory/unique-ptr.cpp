#include <iostream>
#include <memory>
/*
https://thispointer.com/c11-unique_ptr-tutorial-and-examples/
*/
class Shape {
    private:
    public:
        int val;
        
        explicit Shape(int val): val {val} {            
        };

        void display(void) const {
            std::cout << "val: " << val << std::endl;
        }
};

int main(int argc, char *argv[]){
    
    //std::unique_ptr<Shape> ptr1 {new (std::nothrow) Shape { 100 } };
    std::unique_ptr<Shape> ptr1 { std::make_unique<Shape>(100) };
    std::unique_ptr<Shape> ptr2 ;
    
    if (ptr1) {
        std::cout << "ptr1 is Good !!!" << std::endl;
        ptr1->display();
    } else {
        std::cout << "ptr1 is null!!!" << std::endl;
    }
    // ptr2 = ptr1; Not supported, gives compilation err
    ptr2 = std::move(ptr1);
    ptr2->display();
    /*check if unique_ptr ptr1 is still managing the resource.
    Now, it is not... it is a safety check.
    */
    if (ptr1) { 
        ptr1->display();
    } else {
        std::cout << "ptr1 is no more managed !" << std::endl;
    }
    return 0;
}