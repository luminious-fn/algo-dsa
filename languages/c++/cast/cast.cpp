#include<iostream>
#include<string>
using namespace std;

/*
clear;g++ cast.cpp  && ./a.exe
*/
class base {
        public:
            virtual void dump_v() {
                cout << __FUNCTION__ << " base" << endl;
                return;
            }            
            void dump_v1() {
                cout << __FUNCTION__ << " base" << endl;
                return;
            }
};
class derived: public base {
        public:
            int a;
            void dump_v() {
                cout << __FUNCTION__ << " derived" << endl;
                return;
            }
            void dump_v1() {
                cout << __FUNCTION__ << " derived " << endl;
                return;
            }
};

int main(int argc, char *argv[]) {
#if 0 
    // const_cast<type>(object)
    string str("AY");
    const char *cstr = str.c_str();
    char *nonconst_cstr  = const_cast<char *> (cstr) ; 
    *nonconst_cstr = 'B';    
    cout << "nonconst_cstr:= " << nonconst_cstr << " cstr:= " << cstr <<  endl;
#endif

#if 1
    // static_cast
    //int a = 10;    
    double double_var { 10.3 };    
    int q = static_cast<int>(double_var); 
    q = int(double_var);
    std::cout << q << std::endl;

    double *double_ptr { nullptr };
    //int *int_ptr = static_cast<int*> (double_ptr);

    //int* p = static_cast<int*>(&c);
#endif

#if 1
    base *bp ;
    //base b;
    //bp = &b;
    derived d, *dp = nullptr;
    bp = &d;
    //dp = dynamic_cast<derived *> (&b); why this error?
    cout << " before cast " << endl << flush;
    //dp = bp;
    dp = dynamic_cast<derived*> (bp);
    cout << "cast done " << endl << flush;
    if(dp) {
        cout << "dddd" << endl << flush;
        dp->dump_v1();
    } else {
        cout << "null!!!" << endl << flush;
    }
#endif
    
    cout << " main Returns : " << endl;

    return 0;
}