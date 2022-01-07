/*
export PROG="bubble-sort-non-decreasing";clear; g++ $PROG.cpp -o $PROG.exe && ./$PROG.exe 
*/
#include<iostream>
#include<array>
using namespace std;

template<typename T, std::size_t size>
void print_arry1(const std::array<T, size> &myArray) {
    for (T i: myArray) {
        std::cout << i << " " ;
    }
}

template<typename T>
void swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
    return;
}

template<typename T, std::size_t size>
void bubble_sort_non_dec(std::array<T, size>  &arr){
    
    int i, j; 
    bool swapped; 
    for(i = 0; i < arr.size() - 1; i++){
        swapped = 0;
        for(j=0; j < (arr.size() - 1) - i; j++){
            //simply change sign, it will change sort order!
            if(arr[j] > arr[j + 1]){ 
                swap<int>(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if(!swapped) {
            break;
        }
    }  
}

int main(int argc, char *argv[]){

    std::array<int, 3> myArray {1, 324, 5};
    bubble_sort_non_dec(myArray);
    std::cout << std::endl;
    print_arry1<int>(myArray);

    return 0;
}