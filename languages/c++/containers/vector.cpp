#include<iostream>
#include<vector>
//#include<set>
#include<map>
#include<algorithm>

using namespace std;


int main(int argc, char *argv[]){

    /* ------- Vector --------- */
    const unsigned int vlen = 10;
    std::vector<int> v;    
    for(int i = vlen - 1; i >= 0 ; i--){
        v.push_back(i);
    }
    for (unsigned int i = 0; i < v.size(); i++){
        std::cout << v[i] << ", ";
    }
    std::cout << std::endl;

    std::vector<int>::const_iterator it;
    it = v.cbegin();
    while(it != v.cend()){
        std::cout << *it << ", ";
        it++;
    }
    
    std::cout << "\nmin element = " << *std::min_element(v.cbegin(), v.cend());
    std::cout << "\nmax element = " << *std::max_element(v.cbegin(), v.cend());

    std::cout << std::endl;
    std::sort(v.begin(), v.end());
    
    it = v.begin();
    while(it != v.cend()){
        std::cout << *it << ", ";
        it++;
    }     
    std::cout << std::endl;

/* ------- Set --------- */
    std::cout << "set " << std::endl;
    std::set<int> s;
    std::set<int>::const_iterator it1;
    s.insert(7);
    s.insert(10);
    s.insert(7);
    s.insert(7);

    it1 = s.cbegin();
    while(it1 != s.cend()){
        std::cout << *it1 << ", ";
        it1++;
    }

    /* ---- map ------- */
    std::cout << "map" << std::endl;
    std::map<std::string, std::string> m;
    m.insert( std::make_pair("6", std::string { "hello" } ));
    m.insert( std::make_pair("8", "world"));
    m.insert( std::make_pair("10", "gadag"));
    m.insert( std::make_pair("6", "gadag"));
    m["6"] = "gadag";

    std::map<std::string, std::string>::const_iterator it2;
    it2 = m.cbegin();
    while(it2 != m.cend()){
        std::cout << std::endl;
        std::cout << it2->first << " : " << it2->second << ", ";
        ++it2;
    }
    return 0;
}
