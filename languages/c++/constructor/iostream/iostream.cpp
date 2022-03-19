#include<iostream>
#include<string>
#include<iomanip>
int main(int argc, char *argv[]) {
    
    std::string str { "hello" };
    std::string hex_string;
    int dec_val { 14 };
    std::cout << str << std::endl;
    std::cout << std::setiosflags(std::ios_base::hex) << std::setfill('*') << std::setw(10) << str << std::endl;
    std::cout << "0X" << std::hex << dec_val << std::endl;
    hex_string << "0X" << std::hex << dec_val << std::endl;
    
    return 0;
}