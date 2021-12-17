/*
https://www.cprogramming.com/tutorial/c/lesson17.html
clear; gcc var-args.c && ./a.exe
*/

#include<stdio.h>
#include<stdarg.h>


/* following function takes variable number of double args.
in printf(), we specify the format string, and it is where 
it know the type of next varible. Here, we have choosen only
double.
*/

double my_var_arg_function(int junk, int num_of_args, ...) {
    va_list my_args;
    va_start(my_args, num_of_args); // access one before given variable in stack
    /* this directly goes to stack and reads one after the int */

    double temp;
    for(int i=0; i< num_of_args; i++){
        temp = va_arg(my_args, double);
        printf("\n you passed %f", temp);
    }
}
int main(int argc, char *argv[]) {
    my_var_arg_function( 76, 3, 123.1, 243.3, 867.2);
    return 0;
}
