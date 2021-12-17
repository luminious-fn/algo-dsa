/*
export PROG="bubble-sort-non-decreasing";clear; g++ $PROG.cpp -o $PROG.exe && ./$PROG.exe 
*/

#include<iostream>
using namespace std;

void print_arry(int arr[], int len) {
    for(int i=0; i<len; i++) {
        cout << arr[i] << " " ;
    }
}
void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
void bubble_sort_non_dec(int arr[], int size){
    int i, j; 
    int swapped;

    for(i = 0; i < (size - 1); i++){
        swapped = 0;
        for(j=0; j < (size - 1) - i; j++){
            //simply change sign, it will change sort order!
            if(arr[j] > arr[j + 1]){ 
                swap(&arr[j], &arr[j + 1]);
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
    bubble_sort_non_dec(arr, size);
    print_arry(arr, size);

    return 0;
}