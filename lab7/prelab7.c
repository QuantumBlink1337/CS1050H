#include <stdio.h>
void getCount(int * outputInt);
void getIntegerArray(int * outputIntArray, int count);
void printArray(int a[], int size);

int main(void) {
    int array[256];
    int count = 0;
    printf("Welcome to PreLab 7!\n");
    getCount(&count);
    getIntegerArray(array, count);
    printArray(array, count);
}
void getCount(int * outputInt) {
    printf("How many integers do you want in your array?\n");
    scanf("%d", outputInt);
}
void getIntegerArray(int * outputIntArray, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter integer #%d: \n", i);
        scanf("%d", outputIntArray);
        outputIntArray++;
    }
}
void printArray(int a[], int size) {
    printf("Your array has %d integers inside of it.\n", size);
    for (int i = 0; i<size; i++) {
        printf("     Element at index %d: %d\n", i, a[i]);
    }

}