/*  ==============================
    Course: CS 1050H
    Semester: Fall 2021
    Date: 9/3/2021
    Lab: Lab 2
    Author: Matthew Marlow
    Pawprint: mm7f5
    My Day: Good, how about yours?
    ===============================
*/
#include <stdio.h>
int main() {
    int a,b,c,d;
    printf("Enter in four integers, separated by space\n");
    
    // scan function reads all four values at once
    scanf("%i %i %i %i", &a,&b,&c,&d);
    
    // general print statements
    printf("Your values inputted:\nA: %i\nB: %i\nC: %i\nD: %i\n", a,b,c,d);

    printf("General calculations:\n");
// opted to include the operator just inside the print statement to save space
    printf("The sum of A and D: %i\n", a+d);
    printf("The product of B and D: %i\n", b*d);
    printf("The integer quotient of C and A: %i\n", c/a);
    printf("The integer remainer of D and C: %i\n", d % c);
    printf("The quantity A times B divided by the quantity C plus D: %i\n", (a*b)/(c+d));

    // Honors Section of the Code
    // pls don't hate for casting :(
    printf("HONORS ONLY: Exact values of all four values divided by 2\n");
    printf("A / 2: %f\n", ((double)a/2));
    printf("B / 2: %f\n", ((double)b/2));
    printf("C / 2: %f\n", ((double)c/2));
    printf("D / 2: %f\n", ((double)d/2));
    
}
