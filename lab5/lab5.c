/*  ==============================
    Course: CS 1050H
    Semester: Fall 2021
    Date: 10/1/2021
    Lab: Lab 5
    Author: Matthew Marlow
    Pawprint: mm7f5
    My Day: Good, how about yours?
    ==============================
*/
#include <stdio.h>
#include <math.h> // honors-only

// prototypes
double long factorial(int n);
double number_e();
int power_of_e(double e);

int main(void) {
    // chose to just assign the return of the function to e since I use it more than one
    double e = number_e();
    printf("%.10f\n", e);
    power_of_e(e);
    return 0;
}
double number_e() {
    double e = 1.0;
    // idk if this needs to go 25 times but it produced the value I needed. 
    for (double i = 1.0; i <= 25.0; i += 1.0) {
        // adds the next value to e
       e += (1.0/factorial(i));
       //printf("e at %lf: %.10lf\n", i, e);
    }
    return e;
}
// HONORS SECTION
// decided to break this into its own function since it's doing a specific task
int power_of_e(double e) {
    // rubric specified that it only needed to go to the 5th power
    for (int i =1; i <= 5; i++) {
        printf("Power of e to the %d power: %.3f\n", i, pow(e, i));
    }
    return 0;
}


// JIMR WHYYYYYY
// this DOES NOT WORK in the current form. changing it to double long will prevent an overflow on the long data type.
double long factorial(int n) {
    double long result=1;
    for (int i=n; i>1;i--) {
        result*=i;
    }
    //printf("Factorial: %ld\n", result);
    return result;
}
