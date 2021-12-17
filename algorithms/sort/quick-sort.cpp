#include<iostream>
#include "my-lib.hpp"
#include <unistd.h>

using namespace std;

size_t partition(int a[], size_t left, size_t right) {
    cout << "partition left: "<< left << " right: "<< right << "\n";
    size_t pivot = left;

    while(1) {
        usleep(1000000 *.4 );
        cout << "\nShift";
        cout << "\n-->left starts";
        while(left < pivot) {
            if(a[left] > a[pivot]){
                cout << "\nswap";
                swap(&a[left], &a[pivot]);
                pivot = left;
                break;
            } else {
                left++;
            }
        }
        cout << " ends, left: " << left << " pivot: " << pivot;
        cout << "\n<--right starts, ";
        while(right > pivot){
            if(a[right] < a[pivot]){
                cout << "\nswap";
                swap(&a[right], &a[pivot]);
                pivot = right;
                break;
            } else {
                right--;
            }
        }
        cout << " ends, right: " << right<< " pivot: " << pivot;
        if((left ==pivot) && ( right==pivot)) {
            cout << "breaking ...";
            break;
        }
    }
    cout<< "\npivot: " << pivot << "\n";
    return pivot;
}

void quick_sort(int array[], size_t left, size_t right) {
    cout<< "quick_sort left: " << left << " right: " << right << "\n";
    print_array(&array[left], right+1 - left);

    if( left >= right ) {
        cout << "quick_sort: return\n";
        return;    
    }
    int new_partition_index = partition(array, left, right);

    if ( (new_partition_index - left) > 0) {
        cout<< "left sub arr : \n";
        quick_sort(array, left, new_partition_index - 1 );
    } else {
        cout<< "left sub arr Qsort SKIPPED\n";
    }

    cout<< "right sub arr : \n";
    quick_sort(array, new_partition_index + 1, right );
}

int main(int argc, char *argv[]) {
    int array[] = { 3, 2, -100, -9};
    size_t size = sizeof(array) / sizeof(array[0]);
    size_t left = 0; 
    size_t right = size - 1; 

    //print_array(array, size);
    quick_sort(array, left, right);
    print_array(array, size);
}


