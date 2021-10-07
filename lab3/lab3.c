/*  ==============================
    Course: CS 1050H
    Semester: Fall 2021
    Date: 9/10/2021
    Lab: Lab 3
    Author: Matthew Marlow
    Pawprint: mm7f5
    My Day: Good, how about yours?
    ===============================
*/


/*
    I had an idea to set a char to "SQUARE"  and have each print statement also 
    output the value of the charinstead of forcing a check each time,
    but it printed weirdly. Would appreciate help after the lab to figure out why 
    this is. 
*/


#include <stdio.h>
int main(void) {

    // moves in even numbers instead of checking whether a number is even or odd 
    for (int i = 50; i > 1; i -=2) {
        int sqrt = 0; // booleans don't exist in C, so just use int
 
	// HONORS SECTION 
        // handles deciding whether a number is a perfect square. used a double for g
        // to force it to evalutate if it is EXACTLY zero and not a rounded number
        for (double g = 6; g >= 2; g--) {
            if (i / g == g) {
                sqrt = 1;
            }
        }
            // checks to see if it's divisible by both 5 and 3
            if (i % 5 == 0 && i % 3 == 0) {
                if (sqrt == 1) {
                    printf("XYSQUARE\n");
                }
                else {
                    printf("XY\n");
                }   
            }
            // just divisible by 5
            else if (i % 5 == 0) {
                if (sqrt == 1) {
                    printf("XSQUARE\n");
                }
                else {
                    printf("X\n");
                }
            }
            // just divisible by 3
            else if (i % 3 == 0) {
                if (sqrt == 1) {
                    printf("YSQUARE\n");
                }
                else {
                    printf("Y\n");
                }
            }
            // neither :(
            else {
                if (sqrt == 1) {
                    printf("%dSQUARE\n", i);
                }
                else {
                    printf("%d\n", i);
                }
            }
    }
}
