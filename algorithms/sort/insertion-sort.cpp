/*
 * Merge Sort implimentaion
 * 
 export PROG=insertion-sort; clear; g++ $PROG.cpp -o $PROG.exe && ./$PROG.exe 
*/

#include<iostream>
using namespace std;
void print_arry(int array[], size_t len) {
    cout << "print_array: [ ";
    for(size_t i = 0; i < len; i++) {
        cout<< array[i] << ", ";
    }
    cout<< "]\n";
}

void insertion_sort(int a[], size_t len) {
    int i, j,key;
    for(i = 1; i< len ; i++ ) {
        key = a[i];
        cout << "\ni=" << i << " "; print_arry(a, len);
        j = i - 1;
        while(j >= 0 && key < a[j]) {
            cout << "==> j = " << j << " \n";
                a[j+1] = a[j];
                j--;
        }
        a[j+1] = key;
    }
}

int main(int argc, char* argv[]) {
    int array[] = {4, 0, 3, 2, 1};
    
    print_arry(array, sizeof(array)/sizeof(array[0]));
    
    insertion_sort(array, sizeof(array)/sizeof(array[0])); 
    
    print_arry(array, sizeof(array)/sizeof(array[0]));
    return 0;    
}
