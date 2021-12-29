#include<iostream>
#include<string>

using namespace std;
/*
indent -linux -brf math.cpp
export PROG=string; g++  $PROG.cpp && ./a.out

*/

int main(int argc, char *argv[]) {
    string s1 = "hello";
    string s2 = " world";
    string 
    s3 = s1 + s2;
	cout << s3 << " " << s3.size() << endl;
	return 0;
}
