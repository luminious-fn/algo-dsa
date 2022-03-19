#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using std::string;
using std::cout;
using std::cin;
using std::vector;
/*
g++ string.cpp && ./a.exe
*/

template <typename T>
void from_string(const string & s_string, T &x, T &y){
    std::stringstream str_stream { s_string };
    std::string s;
    str_stream >> x >> y >> s;
}

void toupper(string &s){
    for (auto &c : s){
        c = std::toupper(c);
    }
    cout << s;
}

int main(int argc, char *argv[]){
    
    string s1 {"8.987 9.999 alm_reaction"};
    /* C strings are not c++ string objects. So, we can't concat two C strings like below*/
    // string s2 = "dd" + "ee" + string {"ee"}; // error since scaning from left, first + can't be applied to C strings
    string s2 = "dd" + string {"ee"}; // Not an error since + overloaded c++ operator takes care of it!
    //string s2 = "dd" + "ee" + string {"ee"};
    cout << "str: " << s1 << std::endl;
    cout << "size: " << s1.size() << std::endl;
    cout << "empty: " << (s1.empty()?"true":"false") << std::endl;
    cout << "max_size(): " << s1.max_size() << std::endl;
    cout << "capacity(): " << s1.capacity() << std::endl;
    //std::cout << "reverse(): " << s1.reverse() << std::endl;

    const char *c_str = s1.c_str();
    cout << "c_str: " << c_str << std::endl;    
    
    double x, y;
    from_string(s1, x, y);
    cout << x << ", " << y << std::endl;

    string s3 { "hello" };
    toupper( s3 );

    vector<string> s4 {19, "d"};
    for (auto i : s4){
        cout << i;
    }

    return 0;

}