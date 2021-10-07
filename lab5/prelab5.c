#include <stdio.h>
int myPow(int n, int p);

int main(void) {
    printf("Power: %d", myPow(2,2));
    return 0;
}
int myPow(int n, int p) {
    int number = n;
    for (int i=0; i < p-1; i++) {
        number*=number;
    }
    return number;
}