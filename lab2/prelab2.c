
#include <stdio.h>
int main (void) {

	int x,y;
	
	printf("Enter a integer!\n");
	scanf("%d",&x);
	printf("Enter another integer\n");
	scanf("%d",&y);

	printf("Your first number was %d. Your second integer is %d.\n", x, y);
	printf("Value of x multipled by y: %d \n", x * y);
	printf("Value of x divided by y: %d \n", x / y);
	printf("Value of x + 1 multipied by y: %d \n", (x+1) * y);
	printf("Both values remain unchanged in memory: %d, %d\n", x, y); 	


}

