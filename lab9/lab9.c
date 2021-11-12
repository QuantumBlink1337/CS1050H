/*  ==============================
    Course: CS 1050H
    Semester: Fall 2021
    Date: 10/29/2021
    Lab: Lab 9
    Author: Matthew Marlow
    Pawprint: mm7f5
    My Day: Does anyone even read these?
    ===============================
*/


#include <stdio.h>

void createString(char* inputString);
void getSize(char* const array, int* size);
void defineDivisor(int* divisor);
void printArray(char* const array);
void substringCreation(char *array, int s, int divisor);

int main(void) {
    // all full assignment of variables done through pointer calls
    char array[256];
    int divisor = 0;
    int size = 0;
    printf("Welcome to Lab 9!\n");
    createString(array);
    getSize(array, &size);
    defineDivisor(&divisor);
    printArray(array);
    substringCreation(array, size, divisor);
    printf("Thanks for doing Lab 9!\n");
}
// defines the segment length divisor using pointers
void defineDivisor(int* divisor) {
    printf("Please enter a segment length.\n");
    scanf("%d", divisor);
}
// allows user to define their word and uses pointer to assign it
void createString(char* inputString) {
    printf("Enter a word.\n");
    scanf("%s", inputString);
}
// get size of char array by checking when the null terminator appears
void getSize(char* const array, int* size) {
    int i = 0;
    while (*(array+i) != '\0') {
        i++;
    }
    *size = i;
}
// prints string
void printArray(char* array) {
    printf("You entered: %s\n", array);
}
void substringCreation(char*array, int s, int divisor) {
    int size = s;
    // if the size is smaller than the divisor, then there has to be only one segment so just stop here
    if (size < divisor) {
        printf("There is 1 segment in your string.\nThe modified string is: %s\n", array);
    }
    else {
        char temp[256];
        int segments = 0;
        int j =0;
        /*
            I chose to write this section to code to account for the "exception",
            that is for when the string coming is not divisible cleanly by the divisor.
            I used modulus to figure out how big the odd characters out were in the string, and add
            those first. I subtract for how big the "odd" string is out of the original size, and cleanly
            divide up the rest of the string without the first part. 
        */
        int modulus = size % divisor;
        // if the string is cleanly divisible, dw about this section and move to standard sectioning
        if (modulus != 0) {
            // use pointers to define what index we're working with
            char* highEnd = (array+size);
            char* lowEnd = (array+size-modulus);
            // sets the first part of temp to the characters we found that were the "odd ones out"
            while (lowEnd < highEnd) {
                *(temp+j) = *lowEnd;
                j++;
                lowEnd++;
                // subtracts from size to prevent us from reaccessing these characters in the next loop
                size--;
            
            }
            // we just do this once because this section only finds one segment
            segments++;
        }
        // this section assumes the string is cleanly divisible. assuming you just came from the if statement, it now is. 
        for (int i = size; i > 0; i-= divisor) {
            segments++; // everytime this loop runs, we found a new segment
            // similar to above code in that we use pointers to define the bounds of the segment
            char* highEnd = (array+i);
            char* lowEnd = (array+i-divisor);
            while (lowEnd < highEnd) {
                *(temp+j) = *lowEnd;
                j++;
                lowEnd++;
            }
        }
        // assigns the temp character values back to the original array
        for (int i = 0; i < s; i++) {
            *(array+i) = *(temp+i);
        }
        printf("There is %d segments in your string.\nThe modified string is: %s\n", segments, array);
    }
}