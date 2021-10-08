/*  ==============================
    Course: CS 1050H
    Semester: Fall 2021
    Date: 10/8/2021
    Lab: Lab 6
    Author: Matthew Marlow
    Pawprint: mm7f5
    My Day: UPUPDOWNDOWNLEFTRIGHTLEFTRIGHTBASTART
    ===============================
*/
#include "stdio.h"
#define SIZE 100
int initializeArray(int array[], int begin, int end, int increment);
void multiplyArrayTogether(int array1[], int array2[], int productArray[], int size);
void printArrays(int array1[], int array2[], int array3[], int size);
void invertArray(int array[], int size, int invertedArray[]);

int main(void) {
    int array1[SIZE], array2[SIZE], array3[SIZE], invertedArray[SIZE];
    int size;
    // array1 and array2 will be the same size so this can be safely be reused. 
    // had they not been the same size, we'd need to use two separate size variables. 

    
    size = initializeArray(array1, 1, 31, 3);
    initializeArray(array2, 2, 52, 5);
    multiplyArrayTogether(array1, array2, array3, size);
    printf("First set of arrays\n");
    printArrays(array1, array2, array3, size);
    // generates an inverted version of array2 and sets it to invertedArray
    invertArray(array2, size, invertedArray);
    // uses the invertedArray which we know to be the inverse of array2 
    multiplyArrayTogether(array1, invertedArray, array3, size);

    printf("First set of arrays Reverse Multiplied\n");
    // reuse array2 to match given example output
    printArrays(array1, array2, array3, size);
    

    /*
        The same code from before is repeated with the exception of the new parameters of initializing array1
        and array2. 
    */

    size = initializeArray(array1, 22, 0, -2);
    initializeArray(array2, 84, 0, -7);
    multiplyArrayTogether(array1, array2, array3, size);
    printf("Second set of arrays\n");
    printArrays(array1, array2, array3, size);
   
    invertArray(array2, size, invertedArray);
    multiplyArrayTogether(array1, invertedArray, array3, size);
    printf("Second set of arrays Reverse Multiplied\n");
    printArrays(array1, array2, array3, size);

    return 0;
    
}
// given two arrays, multiples the integer at a given index and sets it to the given index of a third array
void multiplyArrayTogether(int array1[], int array2[], int productArray[], int size) {
    for (int i = 0; i <= size; i++) {
        productArray[i] = array1[i] * array2[i];
    }
}
// initializes the arrays based on the begin and end step. also supports negative values as needed with the second set of given parameters
int initializeArray(int array[], int begin, int end, int increment) {
    int i =0;
    if (increment > 0) {
        for (; begin <= end; begin+=increment) {
        array[i] = begin;
        i++;
        }
    }
    else {
        for (; begin >= end; begin+=increment) {
        array[i] = begin;
        i++;
        }
    }
    
    return i;
}
// honors section
// rather than rewrite multiplyArrayTogether I decided to just invert an array input and give it to that
void invertArray(int array[], int size, int invertedArray[]) {
    int s = size; // I suppose this isn't necessary anymore but if you see my commented out code I want size to be intact in case I want to see the inverted array
    for (int i = 0; i < size; i++) {
       invertedArray[s-1] = array[i];
        s--;
    }
    // printf("Array after Inverse\n");
    // printArray(invertedArray, size);

}
// prints the arrays as one line
void printArrays(int array1[], int array2[], int array3[], int size) {
    for (int i = 0; i <= size-1; i++) {
        printf("Array 1 Index %d: %d | Array 2 Index %d: %d | Array 3 (product) Index %d: %d\n", i, array1[i], i, array2[i], i, array3[i]);
    }
}

