/*
I have given due credits using reference links.
https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

clear;g++ fibonacci.cpp  && ./a.exe
*/

#include<iostream>

using namespace std;

int fibonacci_recursion(int n) {
    int fib_number=0;
    if(n <= 1) {
        //cout << fib_number << " ";
        return n;
    } else {
        fib_number = fibonacci_recursion(n-1) + fibonacci_recursion(n-2);
        //cout << fib_number << " ";
        return fib_number;
    }
}

int fibonacci_stored(int n) {
    int fib[n+2];
    fib[0] = 0;
    fib[1] = 1;
    int i;
    for (i = 2; i <= n; i++){
        fib[i] = fib[i-1] + fib[i-2]; 
    }
    return fib[n];
}

int fibonacci_space_optimized(int n) {
    int a = 0, b = 1, c;
    if(n==0){
        return a;
    } else if (n == 1) {
        return b;
    } else {
        for(int i = 2; i <= n; i++){
            c = b + a;
            a = b;
            b = c;            
        }
    }
    return c;
}


int main(int argc,char *argv[]){
    int n = 20;
    int nth_fib;
    nth_fib = fibonacci_recursion(n);
    cout << n << "th fibonacci number: " << nth_fib << endl;

    nth_fib = fibonacci_stored(n);
    cout << n << "th fibonacci number: " << nth_fib << endl;

    nth_fib = fibonacci_space_optimized(n);
    cout << n << "th fibonacci number: " << nth_fib << endl;    

    cout << endl << "main returned" << endl;
}