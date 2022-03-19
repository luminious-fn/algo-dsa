#include<iostream>
#include<string>
#include<memory>

/*
https://www.sourcecodeexamples.net/2020/09/c-factory-method-pattern-example.html
https://iq.opengenus.org/abstract-factory-pattern-cpp/
https://sourcemaking.com/design_patterns/abstract_factory/cpp/before-after


clear; g++ factory.cpp && ./a.exe


*/
/*

Difference between factory method and abstract factory method
The Factory Method pattern uses inheritance and relies on a subclass to handle the desired object instantiation.

Factory Desing pattern
User knows only Abstract Factory class to create real objects.
Abstract class implements a static create method. User user uses this
to create real objects.

Abstract Factory --> creats real instances
User
 
*/
class AbstractFactory {
    public:
        static std::shared_ptr<AbstractFactory> create(std::string name);
        virtual void print_item_details(void) = 0;
};

class ConcreteFactory_1: public AbstractFactory {
    public:
        explicit ConcreteFactory_1(void){            
        }
        void print_item_details(void){
            std::cout << "from Concrete Factory 1\n";
        }
};

class ConcreteFactory_2: public AbstractFactory {
    public:
        explicit ConcreteFactory_2(void){
        }
        void print_item_details(void){
            std::cout << "from Concrete Factory 2\n";
        }
};
class ConcreteFactory_3: public AbstractFactory {
    public:
        explicit ConcreteFactory_3(void){
        }
        void print_item_details(void){
            std::cout << "from Concrete Factory 3\n";
        }
};

std::shared_ptr<AbstractFactory> AbstractFactory::create(std::string name) {
    if(name == "1"){
        return ( std::make_shared<ConcreteFactory_1>() );
    }else if(name == "2") {
        return (std::make_shared<ConcreteFactory_2>() );
    }else if(name == "3"){
        return (std::make_shared<ConcreteFactory_3>() );
    }else {
        return nullptr;
    }
}

int main(int argc, char *argv[] ){

    std::cout << std::endl;
    std::shared_ptr<AbstractFactory> ptr_abstract_a = AbstractFactory::create("1");
    std::shared_ptr<AbstractFactory> ptr_abstract_b = AbstractFactory::create("2");
    std::shared_ptr<AbstractFactory> ptr_abstract_c = AbstractFactory::create("3");

    ptr_abstract_a->print_item_details();
    ptr_abstract_b->print_item_details();
    ptr_abstract_c->print_item_details();
    return 0;
}