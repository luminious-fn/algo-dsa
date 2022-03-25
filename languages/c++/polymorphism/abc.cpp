/*
clear; g++ -std=c++2a abc.cpp  && ./a.exe
*/
#include<iostream>
using namespace std;
class A{
	public:
	virtual void a()=0;
	A(){
		cout<<"A ";
	}
};

class B: public A {
	public:
	B(){
		cout<<"B ";
	}
	/* virtual void a() {}; We have to define  base's pure virtual function
	to create an object of type B. Else this to remain ABC.
	*/
};

int main(){
	//A *a = new B();
	B();
	return 0;
}

