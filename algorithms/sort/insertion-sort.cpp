/*
 * insertion Sort implimentaion
 * 
export PROG=insertion-sort1; clear; g++ $PROG.cpp -o $PROG.exe && ./$PROG.exe 

insertion sort inserts a key element at a right position in already sorted array.

At the begeinging, we need to assume, we have only one element arraay (at index 0).
Then take its next adjecent element as element to be inserted, (array sz =2 since, we take this 
second element's memory is added to new array. now insert this 2nd element to the arr at right position)

repeat for each successive element. 
*/

#include<iostream>
using namespace std;

void print_arr(int array[], int len) {
    cout << "print_array: [ ";
    for(int i = 0; i < len; i++) {
        cout<< array[i] << ", ";
    }
    std::cout<< "]\n";
}

/*
3 |  |
2 |  |
1 |  |
0 |__| start from here
*/

void insertion_sort(int arr[], int size) {
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        /* do the shifting of elements to upper positions */
        while ( j >= 0 && (key < arr[j]) ){
                arr[j + 1] = arr[j];
                j--;
        }
        /* the last upper postion that is shifted and left empty so, 
        place the key there */
        arr[j + 1] = key;
        print_arr(arr, size);
    }
}

int main(int argc, char* argv[]) {
    int arr[] = {4, 0, 3, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    print_arr(arr, size);    
    insertion_sort(arr, size);     
    print_arr(arr, size);
    return 0;    
}
