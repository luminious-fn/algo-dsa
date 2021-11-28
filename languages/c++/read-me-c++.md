Ref 
    - https://www.cprogramming.com/tutorial/c++-tutorial.html?inl=nv    
    - https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/
    - https://www.tutorialspoint.com/cplusplus/cpp_references.htm
    - https://notes.shichao.io/tlpi/ch6/
    - https://notes.shichao.io/books/
        

- statements
- objects, variables, identifiers
- definition and declaration 
- 

## initialization ##
 - copy init using = operator
    - int a = 100;
 - direct init using ()
    - int a(100);
- Brace init
    - int a { 100 };
    - int a = { 100 };
    - int a { }; // default zero or empty init.
- Reference 
    - call by reference
    - return by reference
- Pointers

- Classes
    - https://www.cplusplus.com/doc/tutorial/classes/
    - Class access modifiers: private, public, protected
    - by default, private is assumed
    - class members are defined inside class
    - :: scope resolution operator
    ```c++
    class derived_class : access_sp base1, access_sp base2 {
        access_specifier_1:
            member1;
        access_specifier_2:
            member2;
        ...
    } object_names;

    class MyClassName() {
        public:
            int age;
            int fun(float a);
            MyClassName(); // This is constructor.
            ~MyClassName(); // This is constructor.

    }

    /* no return variable for constructor and destructor. */

    MyClassName::MyClassName(float) {        
    }    
    int MyClassName::~MyClassName(float) {
    }    
    int MyClassName::fun(float) {
        return 0;
    }    
    ```
- inline function: if we prefix `inline` keyword before a function definition,
    compiler places the copy of function body at place it gets called.
    This is used where even function call can be thought as time consuming.
    - all functions defined inside the class definition block is the inline 
- function argument name vs member name
    - it is not good idea to keep function argument name same as member name.
    but if that happend, block level variable (= function arg) has higher precedence over
    the member variable. In that case, once has to use `this` pointer
- static member variable and static member functions
- constructor : It is called during creation of an object. It does not have 
    a return type. Not even void.
- Destructor: It will neither take an argument, nor return anything.
- Friend function is a function outside a class yet has access to all members of the class.
    to declare a function as friend, use friend key word inside class definiation
    and put function prototype.
    friend <ret_val> function_name(class_name class_object)
    Yes, for friend function whole class object to be passed, always!

- encapsulation
    - class attributes can be encapsulated inside the class so that it will not  
    be visible to its users. This is used to change the attributes without the  
    the user being impacted.  
    This is done using private declaration.
- Multilevel  inheritance Vs multiple inheritance
- inheritance
    -
    ```c++
    class vehicle {
        public:
            string model = "generic";
    };
    class car :: public vehicle {
        public:
        string model = "tata";
    };
    ```
 ## function and operator over loading ##
    - https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
    - should happen in the same scope for all realted functions.
    - overload resolution
    - function signature consists of function name, parameter list including their types.
        - this does not include return types. 
    - Within a class (or in a namespace), we can define a function with same 
    name/return type but with different parameter types/numbers. Each such case
    providing different implementation. Thus a function name is overloaded with
    many implementation. ie function name should be same, but rest of signature should be 
    different.
    - Overloading does not work based on return type. ie all over loaded functions
    should have same return type and same function names.


## polymorphism ##
    - Poly : many, morph : forms
    A function can have multiple definitions ( many forms ) that are chained in 
    inheritance.      
    A function defined inside a class can be redefined in its child classes.
    Thus we have one function signature, but with different implementation.
    - static linkage/resolution or early binding : decided during compilation time to 
    call which function.
    - dynamic linkage or late binding; decided during run time. Looks not into pointer
    type but goes into content of the pointer is pointing, finds its type and resolves the 
    function to be called.
    - pure virtual function : enforces the function body implementation.
    
## Data Abstraction ##

- https://www.tutorialspoint.com/cplusplus/cpp_data_abstraction.htm
- using private access modifiers, we protect and hide the data from users of our class.
- using public access modifiers, we let user to use our class without bothering them about internal details.
- we we abstract the implemntation for the users our class.
- Designing Strategy
Abstraction separates code into interface and implementation. So while designing your component, you must keep interface independent of the implementation so that if you change underlying implementation then interface would remain intact.

In this case whatever programs are using these interfaces, they would not be impacted and would just need a recompilation with the latest implementation.

## Data encapsulation ##
- `Data encapsulation` is a mechanism of bundling the data, and the functions that use them. This is done 
using `class`
    - typically using private and protected, we hide the data - data hiding,
- `Data abstraction` is a mechanism of exposing only the interfaces and hiding the implementation details from the user. Using public and protected, we expose the interfaces , yet hide all internal details.

## Concrete and Abstract class ##
- https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm
-  if a class contains, at least one pure virtual function, it can not be
use for instantiation and it is called concrete class.
- If a class can be used to instantiation, it is called concrete class.
- abstract classed are used for system design so that they can be used as base 
class in derived class. 

## name spaces ##
- https://www.tutorialspoint.com/cplusplus/cpp_namespaces.htm
- 
```c++
namespace my_ns {
    int a;
    void fun() {
        cout << "dddd";
    }
}

my_ns::fun()
using namespace my_ns;
fun();

using my_ns::fun
fun()
```

## const ##
if const comes after member function, it means, member function can not modify any
member data

int fun( obj ) const;

## smart pointer ##
- https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170
- https://www.internalpointers.com/post/beginner-s-look-smart-pointers-modern-c
- https://www.journaldev.com/37481/smart-pointers-in-c-plus-plus
- https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170&viewFallbackFrom=vs-2019

They are designed to provide a kind of Automatic Garbage Collection to C++ langauge.
This also means RAII - `Resource Aquisation Is Initialization` - a programing paradigm
that make a line of code that creates a resource (es: heap memory object) 
also does the init at the same line. ie it means, pointer will be on stack, and 
memory will be on heap.  And when a stack pointer goes out of scope, heap memory will be 
automatically freed without user doing it explicitly. This can be done using smart pointer.

So, we should try to avoid using C pointer (aka raw pointer in C++). Instead use 
C++ smart pointer in the same place.

Smart pointers exploits the a property present in C++ objects.
ie, when object goes out of scope, its destructor will be called. In that destructor code
we can put heap freeing code... GEnerally done by STL

smart pointer class overload * and -> to mimic the raw pointer operators.

Note: the smart pointer variable should be created on stack, never on heap.
Means, we should not do new of smart pointer. rather, it should be a variable on stack.
because, as a stack variable when it goes out of scope, the meomory pointed by it will 
be free by destructor. But if we create smart pointer on heap, it will never go out of scope
unless we call it explicitly using `delete`. This is not very useful... what if we forget to `delete`,
we back to square 1... so, put the smart pointer variable on stack, and let it point to heap object.

.get() gives raw pointer

unique_port<int> u_ptr  = make_unique<int>(5);
shared_ptr<int> s_ptr = make_shared<int>(4);
weak_ptr<int> w_ptr = s_ptr;

## cast ##  
- https://www.tutorialspoint.com/cplusplus/cpp_casting_operators.htm

## dynamic cast ##
- https://www.geeksforgeeks.org/dynamic-_cast-in-cpp/
- https://www.tutorialspoint.com/cplusplus/cpp_casting_operators.htm
- https://www.cplusplus.com/doc/tutorial/typecasting/