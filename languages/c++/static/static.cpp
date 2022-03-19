#include<iostream>
using std::cout;
/*
 g++ static.cpp && ./a.exe
 */
class st {
public:
	static int x;
};


int main(int argc, char *argv[]){
	int st::x = 88;
	cout << st::x;
}
