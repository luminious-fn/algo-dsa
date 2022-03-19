/*
clear; g++ -std=c++2a inc.cpp  && ./a.exe
*/
#include<iostream>
using namespace std;
int main(){
	int a = 1;
	cout << a++ * ++a << endl;
	return 0;
}

