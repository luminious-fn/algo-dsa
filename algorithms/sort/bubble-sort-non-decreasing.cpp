/*
export PROG="bubble-sort-non-decreasing";clear; g++ $PROG.cpp -o $PROG.exe && ./$PROG.exe 
*/
#include<iostream>
using namespace std;

template<typename T, typename U>
void print_arry(T arr[], U len) {
    for(int i=0; i<len; i++) {
        std::cout << arr[i] << " " ;
    }
}

template<typename T>
void swap(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
    return;
}

template<typename T, typename U>
void bubble_sort_non_dec(T arr[], U size){
    int i, j; 
    bool swapped;

    for(i = 0; i < (size - 1); i++){
        swapped = 0;
        for(j=0; j < (size - 1) - i; j++){
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

    int arr[] = {1,324,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubble_sort_non_dec<int, int>(arr, size);
    print_arry<int, int>(arr, size);

    return 0;
}