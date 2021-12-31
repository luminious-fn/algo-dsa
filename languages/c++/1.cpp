#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    // enum enum_name { list of name } list of variables;
    enum color {red, green, blue} a, b, c;
    
    //int y;
    //666 = y; // error!
    int* y = &666; // error!

    a = red;
    b = green;
    c = blue;
    cout << "hello world!" << ", a=" << a << " ,b=" << b << " ,c=" << c << endl;
    return 0;
}