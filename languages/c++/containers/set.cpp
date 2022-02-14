#include<iostream>
#include<set>

/*
g++ set.cpp && ./a.exe
*/
int main(int argc, char *argv[]) {

    std::set<int> int_set { 77, 3, 4 };
    int_set.insert(444);
    int_set.insert(555);

    std::set<int>::iterator it;    
    std::set<int>::const_iterator cit;    
        
    for(it = int_set.begin(); it != int_set.end(); it++) {
        std::cout << *it << ", ";
    }

    std::cout << " \n";

    for( cit = int_set.begin(); cit != int_set.end(); cit++ ){
        std::cout << *cit << ", ";        
    }

    std::cout << "\n";

    for(auto it = int_set.cbegin(); it != int_set.cend(); it++ ){
        std::cout << *it << ", ";        
    }

}
