#include <iostream>
using namespace std;

/*
export PROG="anagram";clear; g++ $PROG.cpp -o $PROG.exe && ./$PROG.exe 
*/

/*
returns false : if not anagrams
returns true : if anagrams
*/


float median(int arr[], int n) {
    float median;
    if ( (n%2) == 0 ) {        
        median = (arr[n/2] + arr[(n/2)-1]) / 2.0;
    } else {
        median = arr[n/2];
    }
    return median;
}

/* aka as mean or average*/
float arithamatic_mean(int arr[], int len) {
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += arr[i];
    }
    float mean = sum / len;
    return mean;
}

int main(int argc, char *argv[]) {

    int arr[] = { 1, 3, 4, 2, 7, 5, 8, 6 };
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << "median = " << median(arr, len) << endl;
}