#include<iostream>
using std::cout;
using std::endl;

/*
 g++ new.cpp && ./a.exe
 * */
int main(int argc, char *argv[]){

	int *p = new int[3] {int(1), 2, 4};
	cout << p[0] << ", " << p[1];
}
