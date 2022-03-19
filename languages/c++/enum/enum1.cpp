#include<iostream>
#include<array>
using namespace std;

/*
indent -linux -brf enum1.cpp
g++ -std=c++2a enum1.cpp && ./a.exe
*/

/*
in C++ for enum, struct/union, class, the typedef is defined automatically.
so we dont need to typedef them explicitly.
*/

int main(int argc, char *argv[]) {
	enum class color { red, green, blue };	// no need of typedef!
	//color a, b, c;
	auto my_color = color::green;
	color your_color = color::blue; // use auto here!
	if (my_color == your_color) {
		cout << "colors are same" << endl;
	} else {
		cout << "colors are not same!" << endl;
	}
	//cout << d << endl; we can print?
	//std::byte dl;
	std::format("ddd");

	return 0;
}

