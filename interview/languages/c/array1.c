/*
 * Merge Sort implimentaion
clear; gcc array1.c -o array1.exe && ./array1.exe 
*/

#include<stdio.h>

void fun(int n1) {
    int arr[n1];
    for ( int i =0; i<n1 ; i++){
        printf("%d, ", arr[n1]);
    }
}

int main(int argc, char *argv[]) {
    int n;
    printf(" enter a number \n");
    scanf("%d", &n);
    fun(n);
    return 0;
}
