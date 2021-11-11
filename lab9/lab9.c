#include <stdio.h>
void invertArray(char* array, int size);
void createString(char* inputString);
int getSize(char* const array);
void printArray(char* const array);
void substringCreation(char *array, int size, int divisor);

int main(void) {
    char array[256];
    printf("Welcome to Lab 9!\n");
    createString(array);
    int size = getSize(array);
    printArray(array);
    substringCreation(array, size, 5);
}
void createString(char* inputString) {
    printf("Enter a word.\n");
    scanf("%s", inputString);
}
int getSize(char* const array) {
    int i = 0;
    while (*(array+i) != '\0') {
        i++;
    }
    return i;
}
void printArray(char* array) {
    printf("You entered: %s\n", array);
}
void substringCreation(char*array, int size, int divisor) {
    if (size < divisor) {
        printf("There is 1 segment in your string: %s", array);
        printArray(array);
    }
    else {
        char temp[256];
        int segments = 0;
        int j =0;
        for (int i = size; i > 0; i-= divisor) {
            segments++;
            char* highEnd = (array+i);
            char* lowEnd = (array+i-divisor);
            while (lowEnd < highEnd) {
                *(temp+j) = *lowEnd;
                j++;
                lowEnd++;
            }
        }
        printf("There is %d segments in your string: %s\n", segments, temp);



    //     for (int i = 0; i < size; i+= divisor) {
    //         char* lowEnd = *array+i;
    //         char* highEnd = *(array+divisor+i);
    //         while (lowEnd > highEnd) {
    //             *(temp + *lowEnd) = *lowEnd;
    //             lowEnd++;
    //         }

    //     }
        
    // }
    }
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