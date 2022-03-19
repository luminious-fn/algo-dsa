#include <iostream>
using std::cout;
using std::endl;
/*
clear;g++ -std=c++2a class.cpp && ./a.exe
*/

class b1 {
	public:
	int x = 20;
	void display(void){
		cout << "base::b1" << endl;
		cout << x << endl;
		cout << b1::x << endl;
	}
};

class derived : public b1 {
	public:
	int x = 10;
	void display1(void){
		cout << "derived" << endl;
		cout << x << endl;
		cout << b1::x << endl;
	}
};

int main(){    
    derived d, *p = &d;
    d.display();
    d.b1::display();    
    return 0;
}