/*  ==============================
    Course: CS 1050H
    Semester: Fall 2021
    Date: 10/15/2021
    Lab: Lab 7
    Author: Matthew Marlow
    Pawprint: mm7f5
    My Day: Does anyone even read these?
    ===============================
*/

#include <stdio.h>
void getIntegerArray(int * outputIntArray, int *countPtr);
void printArray(int *aPtr, int size);
int totalArray(int * array, int count);
float avgArray(int * array, int count);
/// custom defined function. I did not see any penalties for writing your own function in addition to the four given.
float avgTwoArrays(int *array1, int *array2, int count1, int count2);

int main(void) {
    int array[256];
    int array2[256];
    int count = 0;
    int count2 = 0;
    // user defines array1 by defining a size and then fills each element in
    printf("Create array1!\n");
    getIntegerArray(array, &count);
    printArray(array, count);
    printf("Sum of array1: %d\n", totalArray(array, count));
    printf("Average of array1: %.2f\n", avgArray(array, count));
    // same goes for array2
    printf("Create array2!\n");
    getIntegerArray(array2, &count2);
    printArray(array2, count2);
    // I assigned these to variables as I was unsure if arithmetic was permitted
    int totalSum = (totalArray(array, count) + totalArray(array2, count2));
    float totalAverage = avgTwoArrays(array, array2, count, count2);

    printf("Total sum of both array1 and 2: %d\n", totalSum);
    printf("Total average of both array1 and 2: %.2f\n", totalAverage);

}
// prompts user for a count/size, then based on that size we iterate and allow
// user to enter in each integer
void getIntegerArray(int * outputIntArray, int *countPtr) {
    printf("How many integers do you want in your array?\n");
    scanf("%d", countPtr);

    for (int i = 0; i < *countPtr; i++) {
        printf("Enter integer #%d: \n", i);
        scanf("%d", outputIntArray);
        printf("%p\n", (void *) outputIntArray);
        outputIntArray++; // this moves to the next spot in the stack, since the pointer of an array is [0]
    }
}
// takes a pointer to an array and prints it much like getIntegerArray works
void printArray(int *aPtr, int size) {
    printf("Your array has %d integers inside of it.\n", size);
    for (int i = 0; i<size; i++) {
        printf("     Element at index %d: %d\n", i, *aPtr);
        aPtr++;
    }

}
// gets the sum of the integers inside the array
int totalArray(int * array, int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += *array;
        array++;
    }
    return sum;
}
// DRY, so I reused totalArray and cast it to a float to avoid integer division
float avgArray(int *array, int count) {
    float sum = (float) totalArray(array, count);
    return sum / count;
}
// needed a way to average two arrays so I decided to write my own function.
// just calls avgArray twice given the extra parameters and returns the average by using 
// the sum of the two counts given. 
float avgTwoArrays(int *array1, int *array2, int count1, int count2) {
    float sum1 = (float) totalArray(array1, count1);
    float sum2 = (float) totalArray(array2, count2);
    return (sum1+sum2) / (count1+count2);
}