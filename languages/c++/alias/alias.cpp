#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
/*
indent -linux -brf math.cpp
export PROG=alias.cpp; g++  $PROG && ./a.out
*/

int &test(void) {
    static int i = 11; // local variables can be returned even as alias
    return i;
}

int main(int argc, char *argv[]) {
    string name;
    int age;
    cin >>name >> age;	
    cout << name << age;	
	return 0;
}
