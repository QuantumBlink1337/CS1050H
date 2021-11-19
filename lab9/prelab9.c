#include <stdio.h>

void invertArray(char* array, int size);
void createString(char* inputString);
int getSize(char* const array);
void printArray(char* const array);


int main(void) {
    char array1[256];
    int size = 0;
    printf("Welcome to Prelab9.\n");
    createString(array1);
    size = getSize(array1);
    printArray(array1);
    printf("The size of your array is: %d\n", size);
    invertArray(array1, size);
    printArray(array1);

}

void createString(char* inputString) {
    printf("Enter a word.\n");
    scanf("%s", inputString);
}
int getSize(char* const array) {
    int i = 0;
    while (*(array+i) != '\0') {
        i++;
        //printf("getSize i: %d\n", i);
    }
    return i;
}
void printArray(char* array) {
    printf("You entered: %s\n", array);
}
void invertArray(char* array, int size) {
    char* lowEnd = array;
    char* highEnd = array + size - 1;
    while (lowEnd < highEnd) {
        char temp = *lowEnd;
        *lowEnd = *highEnd;
        *highEnd = temp;
        lowEnd++;
        highEnd--;
    }
}
    
    // printf("Array after Inverse\n");
    // printArray(invertedArray, size);
