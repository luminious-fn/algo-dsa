#include <iostream>
#include <string>
//using namespace std;
/* 
Demo of the "Uniform Initalization" syntax from c++11.
Why?: 
This provides clean and consistant syntax for 
initializing all type of variables, for all occasions.

Syntax/Grammar:
type variable {arg1, arg2, ...}

PROG=uniform-initialization.cpp
clear; rm -rf ./a.out;g++ -std=c++11 -Wall  $PROG && ./a.out

ref:
    https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
    https://stackoverflow.com/questions/10828294/c-and-c-partial-initialization-of-automatic-structure
    http://mikelui.io/2019/01/03/seriously-bonkers.html
*/
class Box {
    public:
        int b_arr[3];
        std::string b_str;

        Box(){
            std::cout << "default empty constructor called " << std::endl;
        };

        /* instead of this
        Box(int a, int b, std::string str_val): b_arr(a, b), b_str(str_val) {
        I use uniform initailization as below.
        */
        Box(int a, int b, std::string str_val): b_arr{a, b}, b_str {str_val} {
            std::cout << "constructor called " << std::endl;
            std::cout << this->b_str << std::endl;
        };        
};

int main(int argc, char *argvp[]){

    /* 1 */
    int n {199}; // instead of int n1 = 88;
    /* 2 */
    int arr[5] {1, 2, 3, 40, 50}; // instead of arr[5] = {1, 2, 3, 40, 50}    
    /* number of rows are implicit here: 2
    and , as per std, only first dimension in multi-dim can be left.
    All remianing dim should be mentioned, even when they are obvious!!!    
    */
   /* 3 */
    int arr_2d[][3] { 
        {1, 2, 3},
        {4, 5, 6}        
    };

    /*  
    Typically, for the elements for which value is not given
    will be initialized by zero (more precisely, the default value 
    of the same type static object ) 
    */
    /* 4 */
    int arr_1d[10] { 1, 2, 3};

    /* 5 */
    std::string str {"Blue sky!"}; // string str1 = "Blue sky!"

    std::string str1 {"hellow"};
    std::string str2 {" world"};
    
    /* if I want to init a string using some other existing variables,
    I prefer to do it using "uniform init", rather by using assignment operator    
    ie, I prefer to avoid
    std::string str3 = str1 + str2;
    but do as below to explicitly highlight, it is init operation, not
    after init operation!!!
    */
    std::string str3 { str1 + str2};
    
    std::cout << "str3 = " << str3 << std::endl;

     // single uniform list init 
    int *int_ptr_arr1 = new int[4] {0, 10, 20, 30} ;
    // double uniform list init.
    int *int_ptr_arr { new int[4] {0, 10, 20, 30} };

    /*
    instead of calling a constructor for stack objects as below,
    Box box (1, 2, "earth");
    I use 'uniform init' to explicitly state, it is initialization!
    */
    Box box {1, 2, "earth"};

    /* above technique can be used for
    heap objects too!
    */

    /*for sigle object creation on heap; (note: I dont' use new opeartor but 
    smart pointer!). This is just an example!?  */
    Box *box_ptr = new (std::nothrow) Box { 1, 2, std::string {"mars"} };    

    /* for array of objects creation on heap, using a specific constructor
    note: I prefer smart pointers compared to new/delete... will update the code!
    */
    Box *box_ptr1 = new (std::nothrow) Box[8] { 
        Box {1, 2, std::string {"sun"} }, 
        Box {3, 4, std::string {"moon"} },        
    };

    /*creating array of objects on heap with default constructor 
     here empty curly brackets {} highlight, I am calling default constructor.
    */
    Box *box_ptr2 = new (std::nothrow) Box[2] {};

    /*
    insdie for loop, we can init i = 0, but I do it as 
    i {0}, again wanted to highlight i is initialized (more than assigned)
    */
    for (int i {0}; i < 4 ; i++){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    

    std::cout << "n :" << n << std::endl;
    std::cout << "arr :" << arr[1] << std::endl;   
    std::cout << "str1 :" << str1 << std::endl;
    std::cout << "int arr[1] :" << int_ptr_arr[1] << std::endl;
    std::cout << "int arr[1] :" << int_ptr_arr1[1] << std::endl;    
    std::cout << box.b_str << " " << box_ptr->b_str << " " << box_ptr1->b_str << " " << std::endl;
    return 0;
}
