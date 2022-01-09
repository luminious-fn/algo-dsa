/*
 * Merge Sort implimentaion
   clear; g++ merge-sort.cpp -o merge-sort.exe && ./merge-sort.exe 
   clear; g++ -std=c++2a merge-sort1.cpp -o merge-sort1.exe && ./merge-sort1.exe
   01:01 PM -  1:25 PM
*/

#include<iostream>
#include<array>
template <typename T, std::size_t size>
void print_arry(std::array<T, size> arr) {
    for( auto i: arr) {
        std::cout << i << " " ;
    }
}

template<typename T, std::size_t size>
void merge_sorted_sub_arrays(std::array<T, size> arr, int left, int middle, int right) {
    /*
    allocate two sub arr: L[], R[]
    copy already sorted contents main arr to above two sub arr
    copy back content from L[]/R[] to main arry, while taking care of sort order
    copy any remaining contents from L[]/R[] to main arr
    */

    int left_sub_arr_len = middle - left + 1;
    int right_sub_arr_len = right - (middle+1) + 1;    
    int L[left_sub_arr_len];
    int R[right_sub_arr_len];
    int i;
    for(i = 0; i < left_sub_arr_len; i++ ){
        L[i] = arr[left + i];
    }
    for(i = 0; i < right_sub_arr_len ; i++ ){
        R[i] = arr[middle+1 + i];
    }
    int left_sub_arr_index = 0;
    int right_sub_arr_index = 0;
    int sorted_sub_arr_index = left;

    while( (left_sub_arr_index < left_sub_arr_len) &&
           (right_sub_arr_index < right_sub_arr_len) ){

        if(L[left_sub_arr_index] < R[right_sub_arr_index]) {
            arr[sorted_sub_arr_index] = L[left_sub_arr_index];
            left_sub_arr_index++;
            sorted_sub_arr_index++;
        } else {
            arr[sorted_sub_arr_index] = R[right_sub_arr_index];
            right_sub_arr_index++;
            sorted_sub_arr_index++;
        }
    }
    
    //for(i = left_sub_arr_index; i <left_sub_arr_len; i++ ){
    //    arr[sorted_sub_arr_index] = L[i];
    //}

    while(left_sub_arr_index < left_sub_arr_len){
        arr[sorted_sub_arr_index] = L[left_sub_arr_index];
        left_sub_arr_index++;
        sorted_sub_arr_index++;
    }

    //for(i=right_sub_arr_index; i < right_sub_arr_len; i++) {
    //    arr[sorted_sub_arr_index] = R[right_sub_arr_index];
    //}
    while(right_sub_arr_index < right_sub_arr_len) {
        arr[sorted_sub_arr_index++] = R[right_sub_arr_index++];
        sorted_sub_arr_index++;
        right_sub_arr_index++;
    }
}

template<typename T, std::size_t size>
void merge_sort(std::array <T, size> arr, int left_index, int right_index){
    if(left_index < right_index){  
        int mid_index = left_index +  (right_index - left_index) / 2;
        merge_sort(arr, left_index, mid_index);
        merge_sort(arr, mid_index + 1, right_index);
        merge_sorted_sub_arrays(arr, left_index, mid_index, right_index);
    }
}

int main(int argc, char *argv[]) {
    std::array<int, 7> arr {0, 1000, 2, 4800, 500, 500, 500};
    //int arr_len = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr, 0, arr.size()-1);
    print_arry(arr);    
}
