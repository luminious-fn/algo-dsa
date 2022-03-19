#include<iostream>
using std::cout;
using std::endl;

/*
 g++ diff.cpp && ./a.exe
 */
int main(int argc, char *argv[]){
    int p[] {0x44332211,2,3,4};
    int q[] {1,2,3,4};
    int x;

    char *c = (char*)&p[0];
    for (int i = 0; i < 4; i++){
      	//cout << std::hex << c << " : " << (char)p[i] << endl;
      	printf("%x:%x\n", c+i, *(c+i));
    }
    for (int i = 0; i < 4; i++){
    	cout << std::hex << &p[i] << " : " << p[i] << endl;
    }
    cout << "-----" << endl;

    cout << "x:" << &x << endl;

    cout << "-----" << endl;
    for (int i=0; i<4; i++){
    	cout << &q[i] << " : " << q[i] << endl;
    }

    cout << " ---- " << endl;

    int *ptr {&p[1]};
    //cout << p << " " << q << std::endl;
    //cout << p << " " << q << std::endl;
    //cout << ptr - &q[3] << std::endl;
    cout << "diff1: " << &p[1] - &q[3] << std::endl;
    cout << &p[1] << " " << &q[3] << std::endl;
}
