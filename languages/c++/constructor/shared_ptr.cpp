#include<iostream>
#include<memory>
#include<string>

using namespace std;

/*
clear;g++ shared_ptr.cpp  && ./a.exe
*/

void sp_details(const string &msg, shared_ptr<int> &sp ) {
    //sp?"1":"0"
    cout << msg << " addr:" << sp << ", value: " << (sp?*sp:0) <<  ", count: " << sp.use_count() << endl;
}

int main(int argc, char *argv[]) {

    shared_ptr<int> sp1 = make_shared<int> ();
    *sp1 = 100;
    sp_details("sp1      ", sp1);
    std::shared_ptr<int> sp2, sp3;
    sp2 = sp1;
    sp3 = sp2;
    sp_details("sp2      ", sp2);   
    cout << *sp2;
    sp2.reset();
    
    sp_details("sp2_reset", sp2);   
    sp_details("sp1      ", sp1);   
    
    cout << endl;
    return 0;
}