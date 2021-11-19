#include<iostream>
using namespace std;

#define MY_MACRO(num, str)\
    cout << "num " << num << " is ";\
    cout << str << endl;
int main(int argc, char *argv[]) {
    MY_MACRO(4, "four")
}
