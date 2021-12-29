#include<iostream>
using namespace std;
/*
indent -linux -brf enum1.cpp
*/
/*
in C++ for enum, struct/union, class, the typedef is defined automatically.
so we dont need to typedef them explicitly.
*/
int main(int argc, char *argv[]) {
	enum color { red, green, blue };	// no need of typedef!
	color a, b, c;
	color d = green;
	cout << d << endl;
	return 0;
}
