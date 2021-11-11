#include <stdio.h>
#define SIZE 256

int initializeArray(int array[], int begin, int end, int increment);
int printArray(int array[], int size);

int main(void) {
    int myArray[SIZE];
    printArray(myArray, initializeArray(myArray, 2, 20, 2));
    printArray(myArray, initializeArray(myArray, 1, 97, 3));
    return 0;
}
int initializeArray(int array[], int begin, int end, int increment) {
    int i =0;
    for (; begin <= end; begin+=increment) {
        array[i] = begin;
        i++;
    }
    return i;
}
int printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Element %d = %d\n", i, array[i]);
    }
    return 0;
}