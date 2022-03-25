#include<iostream>

//using namespace std;
using namespace std::cout;
/*
indent -linux -brf math.cpp
g++ -std=c++2a ref1.cpp && ./a.exe
*/

/*
 * if we remove const below, it leads to compilation err.
 * */
template<typename T>
void fun(const T &a) {
	std::cout << a << endl;
	cout << a << endl;
}

int main(int argc, char *argv[]) {
	int a {100};
	fun(a);
	fun(100.8);
	return 0;
}
