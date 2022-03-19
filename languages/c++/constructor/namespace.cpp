#include<iostream>
using namespace std;

namespace first {
    int a = 99;
}
namespace second {
    int a;
}

int main(int argc, char *argv[]){
    cout << first::a << " " << second::a;
    return 0;
}