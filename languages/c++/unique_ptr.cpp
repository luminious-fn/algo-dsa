#include<iostream>
#include<memory>
#include<string>
using namespace std;

/*
g++ shared_ptr.cpp  && ./a.exe
*/

void up_details(const string &msg, unique_ptr<int> &up ) {
    //cout << msg << " addr:" << up << ", value: " << (up?*up:0) << endl;
}

int main(int argc, char *argv[]) {

    std::unique_ptr<int> my_ptr(new int(1), new int(2));


    unique_ptr<int> sp1 = make_unique<int> ();
    *sp1 = 100;
    up_details("sp1      ", sp1);
    //std::unique_ptr<int> sp2;
    //sp2 = sp1;
    //sp_details("sp2      ", sp2);
    
    //sp2.reset();
    //sp_details("sp2_reset", sp2);
    //sp_details("sp1      ", sp2);
    
    cout << endl;
    return 0;
}