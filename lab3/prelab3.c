#include <stdio.h>
int main() {
	int i = 0;
    while(i <= 10); {
        if (i % 2 == 0) {
            printf("Even Number - %d\n", i);
        }
        else {
            printf("Odd Number - %d\n", i);
        }
	i++;
    }
    return 0;
}
