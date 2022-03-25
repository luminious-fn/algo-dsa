#include<iostream>
//using namespace std;
/*
indent -linux -brf math.cpp
g++ -std=c++2a ref1.cpp && ./a.exe
*/

/*
 * if we remove const below, it leads to compilation err.
 * */

class base {
public:
	~base(){
		std::cout << "base cls dtor" << std::endl;
	}
};
class derived : public base {
public:
	~derived(){
		std::cout << " derived dtor" << std::endl;
	}
};

int main(int argc, char *argv[]) {
	base *base_p = new derived;
	delete base_p;
	return 0;
}
