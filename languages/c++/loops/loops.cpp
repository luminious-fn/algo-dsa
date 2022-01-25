#include<iostream>
#include<vector>

/*
indent -linux -brf math.cpp
export PROGRAM loops.cpp; g++ $PRORAM; ./a.exe
*/

int main(int argc, char *argv[]) {	
    std::vector<int> nums;

    nums.push_back(10);
    nums.push_back(20);
        
    for(auto num: nums){
        std::cout<< num << ", ";
    }
	return 0;
}
