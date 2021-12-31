#include <iostream>
#include <string>
using namespace std;

/* 
Demo of the "Uniform Initalization" syntax from c+11.
This provides clean and consistant syntax for 
initializing variables : primitive and aggregate

type variable {arg1, arg2, ...}

ref:
    https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
*/
class Box {
    public:
        int b_arr[3];
        string b_str;
        /* in the following, instead of using round brackets for initialization,
        I used uniform initialization using curly branckets.        
        */
        Box(int a, int b, string str_val): b_arr{a, b}, b_str {str_val} {
            cout << "constructor called " << endl;
            cout << this->b_str << endl;
        };

};

int main(int argc, char *argvp[]){

    int n {199}; // int n1 = 88;
    int arr[5] {1, 2, 3}; // arr[5] = {1, 2, 3}
    string str1 {"Blue sky!"}; // string("")

    int *int_ptr_arr { new int[4] {0, 10, 20, 30} };
    int *int_ptr_arr1 = new int[4] {0, 10, 20, 30} ;

    Box box {1, 2, "earth"};
    Box *box_ptr = new (nothrow) Box { 1, 2, string {"mars"} };
    /* array uniform initialization */
    Box *box_ptr1 = new (nothrow) Box[2] { 
        Box {1, 2, string {"sun"} }, 
        Box {3, 4, string {"moon"} }
    };

    cout << "n :" << n << endl;
    cout << "arr :" << arr[1] << endl;   
    cout << "str1 :" << str1 << endl;
    cout << "int arr[1] :" << int_ptr_arr[1] << endl;
    cout << "int arr[1] :" << int_ptr_arr1[1] << endl;    
    cout << box.b_str << " " << box_ptr->b_str << " " << box_ptr1->b_str << " " << endl;
    return 0;
}
