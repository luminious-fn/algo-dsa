#include<iostream>
using namespace std;

/*
export PROG=member-func.cpp;  g++ $PROG && ./a.out
*/

void getVolume(void){
    cout << "getVolume global" << endl;
}

class Box {
    public:
        static int objCount;
        static void objCount_func(void);
	    int *p;
	    double l, b, h;
	    double getVolume(void);
        double getVolume1(void);
	    Box(double l, double b, double h);
	    Box(double l);
	    Box(const Box & b);	// copy constuctor
	    ~Box();			// destructor do not take parameters !
        friend void display_friend(Box b);
        friend class anotherClass;

    private:
        int pri;
};

void Box::objCount_func(void) {
    cout << __FUNCTION__ << endl;
}

inline Box::Box(double l, double b1, double h1) {
	cout << "3 args constructor" << endl;
	this->l = l;
	b = b1;
	h = h1;
}

Box::Box(double l1) {
	cout << "1 args constructor" << endl;
}

Box::Box(const Box & b) {
	cout << "copy constructor " << endl;
}

Box::~Box() {
	cout << "Destroyed" << this << endl;
}

double Box::getVolume(void) {
    cout << "getVolume" << endl;
	double volume;
	volume = l * b * h;
	return volume;
}

double Box::getVolume1(void) {
    cout << "getVolume1" << endl;
    return getVolume();
}

// copy constructor during parameter passing
inline void display(const Box b) {
	cout << "display" << endl;
}

void display_friend(Box b){
    cout << __FUNCTION__ << endl;
    cout << b.pri << endl;
}

int main(int argc, char *argv[]) {
	Box b1(2, 3, 4);
	Box b2(2);
	Box b3 = b2;
	cout << b1.getVolume() << endl;
	display(b1);
    display_friend(b1);

    cout << b1.getVolume1() << endl;
    Box::objCount_func();
	return 0;
}
