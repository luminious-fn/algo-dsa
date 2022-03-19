#include<iostream>
using namespace std;
/* How to use constructor initializer.
 g++ init.cpp && ./a.exe
 * */
class SomeClass {
public:
	int var1;
	SomeClass(int i): var1(i){
	}
};

class MyClass {
public:
	int var2;
	SomeClass some_class;
	
	MyClass():some_class(7){
		cout << "constructor of MyClass" << endl;
	}
	typedef int sum;
	static int a;
	
};

int MyClass::a = 1000; 

int main(int argc, char *argv[]){
	MyClass my_class;
	cout << "main" << endl;
	             MyClass::sum x {100};
	cout << x << MyClass::a <<endl;
}