#include<iostream>

class Box{
    private:
        int val;
    public:
        const Box operator=(const Box& right_hand_side) = delete;
};

int main(int argc, char *argv[]){
    
    Box b1;
    Box b2;
    /*
    following produces compiler error 
    delete.cpp: In function 'int main(int, char**)':
    delete.cpp:14:10: error: use of deleted function 'const Box Box::operator=(const Box&)'
    b2 = b1;
          ^~
    delete.cpp:7:19: note: declared here
         const Box operator=(const Box& right_hand_side) = delete;
                   ^~~~~~~~
    */
    b2 = b1;
    return 0;
}