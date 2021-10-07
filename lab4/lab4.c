/*  ==============================
    Course: CS 1050H
    Semester: Fall 2021
    Date: 9/17/2021
    Lab: Lab 4
    Author: Matthew Marlow
    Pawprint: mm7f5
    My Day: Good, how about yours?
    ==============================

    I find this code repulsive as I attempted to earn bonus points.
    Just want that on record.
*/


#include <stdio.h>


int main(void) {
    int Start, Limit, Increment;
    // tried to make the rest of these "boolean" integers multiple declared but the program stopped working when I did that
    int validStartInput = 0;
    int validIncrementInput = 0;
    int validLimitInput = 0;

    int incrementNegativity = 0;
    // this is the same as a while loop because the control statement does not use i
    for (int i = 0; validStartInput == 0; i++) {
        printf("Enter Start test\n");
        scanf("%d", &Start);
        validStartInput = ((Start > 1) && (Start < 150)) ? 1 : 0;
    }
    for (int i = 0; validLimitInput == 0; i++) {
        printf("Enter Limit\n");
        scanf("%d", &Limit);
        validLimitInput = ((Limit > 1) && (Limit < 150)) ? 1 : 0;
    }
    for (int i = 0; validIncrementInput == 0; i++) {
        printf("Enter Increment\n");
        scanf("%d", &Increment);
        validIncrementInput = (Start > Limit) ? (Increment < 0 ? 1 : 0) : (Increment >= 0 ? 1 : 0);
    }
    incrementNegativity = (Increment < 0) ? 1 : 0;
    switch (incrementNegativity) {
        case 1:
            for (int i = Start; i >= Limit; i+=Increment) {
                printf("%d ", i);
            }
            break;
        case 0:
            for (int i = Start; i <= Limit; i+=Increment) {
                printf("%d ", i);
            }
            break;
    }
    return 0;
}