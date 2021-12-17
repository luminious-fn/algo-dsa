#include<iostream>
#include "my-lib.hpp"

using namespace std;

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void print_array(int array[], size_t len) {
    cout << "print_array: [ ";
    for(size_t i = 0; i < len; i++) {
        cout<< array[i] << ", ";
    }
    cout<< "]\n";
}

