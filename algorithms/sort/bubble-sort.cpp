#include<stdio.h>
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void print_array(int a[], int len) {
    printf("print_array \n ===>");
    for(int i=0; i<len; i++) {
        printf("a[%d]=%d, ", i, a[i]);
    }
    printf("<<<\n");

    return;
}

void bubble_sort(int array[], const int size) {
    int i, j;
    int swapped = 0;
    for (i = 0; i < (size - 1 ); i++) {
        for ( j = 0; j < ( size - 1 - i); j++ ) {
            if( array[j] > array[j+1] ) {
                swap(&array[j], &array[j+1]);
                swapped = 1;
            }
        }

        if(swapped == 0) {
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    int array[] = { 3, 2, 1, -9};
    int size = sizeof(array) / sizeof(array[0]);
    bubble_sort(array, size);
    print_array(array, size);
}


