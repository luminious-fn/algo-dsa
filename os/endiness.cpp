#include<iostream>
/*
We can check if stack is growing up or down on push!

*/
/*
g++ endiness.cpp && ./a.exe
*/
int global_var1;
int global_var2;

int main(int argc, char *argv[]){
    
    int stack_var1 = 0x44332211;
    int stack_var2;
    std::cout << &stack_var1 << std::endl;
    std::cout << &stack_var2 << std::endl;

    std::cout << &global_var1 << std::endl;
    std::cout << &global_var2 << std::endl;

    char *c = (char *) &stack_var1;    
    std::cout << std::hex << int(c+0) << ":" << int(*(c+0)) << std::endl;  
    std::cout << std::hex << int(c+1) << ":" << int(*(c+1)) << std::endl;  
    std::cout << std::hex << int(c+2) << ":" << int(*(c+2)) << std::endl;  
    std::cout << std::hex << int(c+3) << ":" << int(*(c+3)) << std::endl;  
    return 0;
}