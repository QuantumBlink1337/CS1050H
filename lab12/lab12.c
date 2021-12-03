/*  ==============================
    Course: CS 1050H
    Semester: Fall 2021
    Date: 11/19/2021
    Lab: Lab 12
    Author: Matthew Marlow
    Pawprint: mm7f5
    ===============================
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Movie {
    char title[100];
    long grossRevenue;
    int yearOfRelease;
};
void printMovies(struct Movie* m, int length);
void bubbleSort(struct Movie arr[], int size, char* sortingCondition, int isAdscending); 

int main(int argc, char *argv[]) {
    FILE *fp;


    // if smaller than 2 then no file was specified
    if (argc < 2) {
        printf("No file specified.\n");
        return -1;
    }
    // if the pointer is NULL, we can't open the file for some reason
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File %s cannot be opened.\n", argv[1]);
        return -1;
    }
    // if bigger than 2 then we have a sorting specification
    if (argc > 2) {
        if ((strcmp(argv[2], "Title") != 0) && (strcmp(argv[2], "Gross") != 0) && (strcmp(argv[2], "Year") != 0)) {
            printf("Error in sort field specification.\n");
            return -1;
        }
    }
    // ****HONORS****
    // if bigger than 3, we have a sort order specification
    if (argc > 3) {
        if ((strcmp(argv[3], "Ascending") != 0) && (strcmp(argv[3], "Descending") != 0)) {
            printf("Error in sorting order specification.\n");
            return -1;
        }
    }
   
    int length = 0;
    char* buffer = (char*)malloc(100*sizeof(char));
    // dynamic file length detection ****BONUS****
    do {
        fgets(buffer, 100, fp); // we need to do this to make the file pointer move
        length++;
    }
    while (!feof(fp));
    rewind(fp); // reset file pointer
    struct Movie *movies = (struct Movie*)malloc(length*sizeof(struct Movie));

    for (int i = 0; i < length && !feof(fp); i++) {
         if(fp && !feof(fp)) {
            struct Movie tempMovie;
            /*
                this is safer to do than using fscanf because if we find an error, fscanf will get stuck
                while fgets just moves on
            */
            fgets(buffer, 100, fp); // get the entire line
            sscanf(buffer, "%s %ld %d", tempMovie.title, &tempMovie.grossRevenue, &tempMovie.yearOfRelease); // parse out buffer 
            movies[i] = tempMovie;
            
        }
    }
    fclose(fp);
    free(buffer); // no memory leaks here baby
    printf("********SORTED VALUES***********\n");
    if (argv[2] != NULL) { // if this is null, then just don't do anything
        if (argv[3] != NULL) { // if this is null, just print ascending by default
            if (strcmp(argv[3], "Descending") == 0) { // if descending, pass 0 in
                bubbleSort(movies, length, argv[2], 0);
            }
            else {
                bubbleSort(movies, length, argv[2], 1);
            }
        }
        else {
            bubbleSort(movies, length, argv[2], 1);
        }
    } 
    
    printMovies(movies, length);
    free(movies);

}
void printMovies(struct Movie* m, int length) {
    // I completely guessed on spacing but it works I guess
    printf("%50s%19s%19s\n", "Title", "Gross Revenue", "Year of Release");
    for (int i = 0; i < length; i++) {
        printf("%50s | %15ld | %16d\n", m[i].title, m[i].grossRevenue, m[i].yearOfRelease);
    }
}

void bubbleSort(struct Movie arr[], int size, char* sortingCondition, int isAdscending)
{
    // yeah I know I misspelt isAscending
    void swap(struct Movie *xp, struct Movie *yp);
    int i, j;
    int t, g, y;
    // figure out ahead of time what our sorting specification is
    t = (strcmp(sortingCondition, "Title"));
    g = (strcmp(sortingCondition, "Gross"));
    y = (strcmp(sortingCondition, "Year"));
    // if we got a 1, we can print ascending order
    if (isAdscending == 1) {
        for (i = 0; i < size-1; i++)  {   
       // Last i elements are already in place  
            for (j = 0; j < size-i-1; j++) {
                if (y == 0) { // we got "Year" so sort by year
                    if (arr[j].yearOfRelease > arr[j+1].yearOfRelease)
                    swap(&arr[j], &arr[j+1]);
                }
                else if (t == 0) { // we got "Title" so sort by title
                    if (strcmp(arr[j].title, arr[j+1].title) > 0)
                    swap(&arr[j], &arr[j+1]);
                }
                else if (g == 0) { // we got "Gross" so sort by gross revenue
                    if (arr[j].grossRevenue > arr[j+1].grossRevenue)
                    swap(&arr[j], &arr[j+1]);
                }
            }
        }
    }
    else { // otherwise, we can sort descending since it's not 1
    /*
        pretty much the same thing, only I made i and j the size-1 thing
    */
        for (i = size; i > 0; i--)  {   
       // Last i elements are already in place  
            for (j = size-i; j > 0; j--) {
                if (y == 0) {
                    if (arr[j].yearOfRelease > arr[j-1].yearOfRelease)
                    swap(&arr[j], &arr[j-1]);
                }
                else if (t == 0) {
                    if (strcmp(arr[j].title, arr[j-1].title) > 0)
                    swap(&arr[j], &arr[j-1]);
                }
                else if (g == 0) {
                    if (arr[j].grossRevenue > arr[j-1].grossRevenue)
                    swap(&arr[j], &arr[j-1]);
                }
            }
        }
    }
    
}
void swap(struct Movie *xp, struct Movie *yp)
{
    struct Movie temp = *xp;
    *xp = *yp;
    *yp = temp;
}