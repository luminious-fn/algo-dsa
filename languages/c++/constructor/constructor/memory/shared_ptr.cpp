#include<iostream>
#include<memory>

class Box {
    int a;
    public:
        explicit Box(int a) : a {a} {            
        };        
        void display(void) {
            std::cout << "a: " << a << std::endl;
        }
};

template <typename T>
void use_count(const std::shared_ptr<T> &ptr) {
    std::cout << "count: "<< ptr.use_count() << std::endl;    
    return;
}

int main(int argc, char *argv[]){

    std::shared_ptr<Box> ptr1 {new Box {5} };
    ptr1->display();
    use_count(ptr1);
    {
        std::shared_ptr<Box> ptr2;
        use_count(ptr2);
        ptr2 = ptr1;
        use_count(ptr2);
        use_count(ptr1);
    }
    use_count(ptr1);
    ptr1->display();

    
    return 0;
}