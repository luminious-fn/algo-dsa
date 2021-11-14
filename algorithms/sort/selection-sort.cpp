/*
 * Merge Sort implimentaion
*/

#include<iostream>
#include "my-lib.hpp"

using namespace std;

void selection_sort(int a[], size_t len) {
    int i, j, min_key_index;
    for( i = 0; i < (len-1) ; i++ ) {
        min_key_index = i;
        for( j = i+1; j < len; j++ ) {
            if( a[j] < a[min_key_index] ){
                min_key_index = j;
            }                       
        }        
        swap(&a[min_key_index], &a[i]);
    }
}

int main(int argc, char* argv[]) {
    int array[] = {64, 25, 12, 22, 11};
    
    print_array(array, sizeof(array)/sizeof(array[0]));
    selection_sort(array, sizeof(array)/sizeof(array[0]));
    print_array(array, sizeof(array)/sizeof(array[0]));

    return 0;    
}
