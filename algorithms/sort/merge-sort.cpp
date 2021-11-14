/*
 * Merge Sort implimentaion
clear; g++ merge.cpp -o merge.exe && ./merge.exe 
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

void merge(int array[], size_t left, size_t mid, size_t right) {
    size_t l_len = mid - left +1;
    size_t r_len = right - (mid+1) +1;
    int L[l_len]; 
    int R[r_len];
    for (size_t i = 0; i < l_len; i++) {
         L[i] = array[left + i];
    }

    for (size_t i = 0; i< r_len; i++) {
         R[i] = array[mid+1 + i];
    }    

    size_t i = left;
    size_t l = 0;
    size_t r = 0;
    cout <<"copy starts: left=" << left << "right " << right << "l " << l << "mid" << mid << "r" << r << "\n";
    while( (l < l_len) && (r < r_len )) {        
        cout <<"L" << "[" << l << "]:" << L[l] << ", R[" << r <<"]: " << R[r] << "\n";
        if ( L[l] < R[r] ) {
            cout <<" left cp: \n";
            array[i] = L[l];
            l++;
        } else {
            cout <<" right cp: \n";
            array[i] = R[r];
            r++;
        }
        i++;
    }
    while (l < l_len){
        array[i] = L[l];
        l++;
        i++;
    }
    while (r < r_len ) {
        array[i] = R[r];
        r++;
        i++;
    }
}

void merge_sort(int array[], size_t left, size_t right) {
    cout <<"left: "<< left << ", right: "<< right;
    print_arry(&array[left], right - left + 1);
    if(left == right) {
        return;
    }
    size_t mid = (right - left)/2 + left;
    //cout <<": left " << left << "mid " << mid;
    merge_sort(array, left, mid);
    //cout <<": mid+1" << mid+1 << "right " << right;
    merge_sort(array, mid+1, right);

    merge(array, left, mid, right);

    //cout <<"After merges \n"; print_arry(&array[left], right - left + 1);

}

int main(int argc, char *argv[]) {
    cout <<"Merge Sort\n";
    int array[] = {12, 11, 13, 5, 6, 7 };
    size_t left = 0;
    size_t right = sizeof(array)/sizeof(array[0]) - 1;

    cout <<"Input array \n";
    print_arry(&array[left], right - left + 1);

    merge_sort(array, left, right);

    cout <<"Output array \n";
    print_arry(&array[left], right - left + 1);
    
    return 0;
}

