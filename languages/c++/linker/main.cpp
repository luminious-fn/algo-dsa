/*
 g++ -c main.cpp
 g++ -c lib.cpp
 g++ main.o lib.o -o main.exe

 * */
#include<iostream>
using std::cout;
using std::endl;

extern void print(void);

int main(int argc, char *argv[]){
	cout<< "main" << endl;
	print();
	cout << 5/2 << endl;
}
