/*
 * CS1050
 * Fall 2021
 * Prelab 10 Starter File
 * by Jim Ries
 */

// includes
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Symbolic Constants
#define S1 "Once there was a way to get back homeward"
#define S2 "\n\n\tYou get killed just for      \tlivin' in your\nAmerican skin."
#define S3 "In  these days, you can get no rice.  No razor blades, but you can get knife."
#define S4 "Now some guys they just give up living.  And start dying little by little, piece by piece.      "
#define STRINGCOUNT 4

////////////////
// Prototypes //
////////////////

// KillWhiteSpace should take a string, remove the whitespace from that string in-place,
// and return a pointer to the beginning of the resultant string (which really should
// be the same thing that was passed in originally - i.e., s).
char * KillWhiteSpace(char *s) {
    char temp[256];
    int length = strlen(s);
    printf("Length of s: %zu\n", strlen(s));
    int j = 0;
    char* lowPoint = (s);
    char* highPoint = (s+length);
    while (lowPoint < highPoint) {
        if (!isspace(*lowPoint)) {
            *(temp+j) = *lowPoint;
            j++;
        }
        lowPoint++;
    }
    temp[j] = '\0';
    int i = 0;
    printf("Length of temp: %zu\n", strlen(temp));
    for (i = 0; i < strlen(temp); i++) {
            //printf("%s\n", (temp+i));
            *(s+i) = *(temp+i);
        }
    s[i] = '\0';
    printf("Length of s after reassignment: %zu\n", strlen(s));

    return s;
}


// Main
int main(void)
{
    char s[STRINGCOUNT][256]={S1,S2,S3,S4};

    printf("**** Original Strings ****\n");
    for (int i=0;i<STRINGCOUNT;i++)
    {
        printf("#%d: %s\n",i,s[i]);
    }

    printf("\n\n**** Strings without whitespace ****\n");
    for (int i=0;i<STRINGCOUNT;i++)
    {
        printf("#%d: %s\n",i,KillWhiteSpace(s[i]));
    }
}
