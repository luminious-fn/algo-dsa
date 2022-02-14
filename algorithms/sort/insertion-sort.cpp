/*
 * insertion Sort implimentaion
 * 
export PROG=insertion-sort1; clear; g++ $PROG.cpp -o $PROG.exe && ./$PROG.exe 

insertion sort inserts a key element at a right position in already sorted array.

At the begeinging, we need to assume, we have only one element arraay (at kindex 0).
Then take its next adjecent element as element to be inserted, (array sz =2 since, we take this 
second element's memory is added to new array. now insert this 2nd element to the arr at right position)

repeat for each successive element. 
*/

#include<iostream>
#include<array>

template<typename T, size_t size>
void print_arr(std::array<T, size> &arr) {
    std::cout << "print_array: [ ";
    for( auto &i : arr) {
        std::cout<< i << ", ";
    }
    std::cout<< "]\n";
}

template<typename T, size_t size>
void insertion_sort(std::array<T, size> & arr) {
    int kindex = 1;
    while(kindex < arr.size() ){
        int key = arr[kindex];
        int j = kindex - 1;
        /* do the shifting of elements to upper positions */
        while ( j >= 0 && (key < arr[j]) ){
                arr[j + 1] = arr[j];
                j--;
        }
        /* the last upper postion that is shifted and left empty so, 
        place the key there */
        arr[j + 1] = key;
        kindex++;
        //print_arr(arr);
    }
}

int main(int argc, char* argv[]) {
    std::array<int, 5> arr {4, 0, 3, 2, 1};
    print_arr(arr);  
    insertion_sort(arr);     
    print_arr(arr);
    return 0;    
}