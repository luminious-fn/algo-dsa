#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
/*
indent -linux -brf math.cpp
*/

int main(int argc, char *argv[]) {
	cout << pow(2, 3) << endl;
    srand( (unsigned int) time(NULL));
    for(int i=0; i<10;i++){
        cout<< rand() % 10<< endl;
    }
	return 0;
}
