#include<iostream>
#include<string>
#include<sstream>

template <typename T>
void from_string(const std::string& s_string, T &x, T &y){
    std::stringstream str_stream { s_string };
    std::string s;
    str_stream >> x >> y >> s;
}

int main(int argc, char *argv[]){
    
    std::string s1 {"8.987 9.999 alm_reaction"};
    std::cout << "str: " << s1 << std::endl;
    std::cout << "size: " << s1.size() << std::endl;
    std::cout << "empty: " << (s1.empty()?"true":"false") << std::endl;
    std::cout << "max_size(): " << s1.max_size() << std::endl;
    std::cout << "capacity(): " << s1.capacity() << std::endl;
    //std::cout << "reverse(): " << s1.reverse() << std::endl;

    const char *c_str = s1.c_str();
    std::cout << "c_str: " << c_str << std::endl;    
    
    double x, y;
    from_string(s1, x, y);
    std::cout << x << ", " << y << std::endl;
    return 0;
}