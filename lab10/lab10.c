/*  ==============================
    Course: CS 1050H
    Semester: Fall 2021
    Date: 11/5/2021
    Lab: Lab 10
    Author: Matthew Marlow
    Pawprint: mm7f5
    My Day: Does anyone even read these?
    ===============================
*/


// includes
#include <stdio.h>
#include <ctype.h>
#include <string.h>


// Symbolic Constants
#define CLEARTEXT \
"Haven't felt right in a week\n"\
"And I'm thinning out\n"\
"And it hurts bad\n"\
"I gotta get back\n"\
"\n"\
"Hot head and dreamless sleep\n"\
"I could just slip down\n"\
"And on the wrong track\n"\
"I gotta get back\n"\
"\n"\
"I wanna spend the entire year\n"\
"Just face down\n"\
"And on my own time\n"\
"I wanna waste mine\n"\
"\n"\
"And spend the rest of it asking myself\n"\
"\"Is this who you are?\"\n"\
"And I don't know\n"\
"It just feels gross\n"\
"\n"\
"I don't think there's anything wrong\n"\
"I don't think there's anything wrong\n"\
"And I don't think there's anything wrong\n"\
"I don't think there's anything wrong\n"\
"\n"\
"Sunlight on the back of my arms\n"\
"Just thins me out\n"\
"To a different time\n"\
"I wanna waste mine\n"\
"\"\\\?\n\n\t\t- Snail Mail"



// Prototypes
void Encrypt(const char * in, char * out, int displacement);
void Decrypt(const char * in, char * out, int displacement);

// Main
int main(void) {
    char lyrics[1000] = CLEARTEXT;
    char encryptedLyrics[1000];
    char decryptedLyrics[1000];
    printf("%s", lyrics);
    printf("\n******************************\n            Encrypted Lyrics          \n*****************************\n");
    for (int i = 0; i < strlen(lyrics); i++) {
        Encrypt(&lyrics[i], &encryptedLyrics[i], 99);
    }
    printf("%s", encryptedLyrics);
    printf("\n******************************\n            Decrypted Lyrics          \n*****************************\n");
    for (int i = 0; i < strlen(encryptedLyrics); i++) {
        Decrypt(&encryptedLyrics[i], &decryptedLyrics[i], 99);
    }
    printf("%s", decryptedLyrics);
}


// Function implementations
void Encrypt(const char * in, char * out, int displacement) {
    char input = *in;
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    int characterPosition = -1;
    int lowercase = 0;
    /*
        if the character is uppercase, set
        "boolean" to let us know we'll need
        to convert it to lowercase, and
        back to uppercase at the end of the program

    */
    if (islower(input) > 1) {
        lowercase = 1;
    }
    if (!lowercase) {
        input = tolower(input);
    }
    // find alphabetical position
    for (int i= 0; i < 26; i++) {
        if (alphabet[i] == input) {
            characterPosition = i;
            break;
        }
    }
    // if the character isn't in the alphabet, just add the original char to the
    // encrypted string
    if (characterPosition == -1) {
        in = &input;
        *out = *in;
        return;
    }
    /*
        j represents the index of the encrypted character we want.
        use for loop to run how many times we want it to parse/roll over
    */
    int j = 0;
    for (int i = displacement+characterPosition; i > 0; i--) {
        if (j > 25) {
            j = 0;
        }
        j++;
    }
    // 26 = null terminator
    if (j == 26) {
        j = 0;
    }
    // add encrypted char to string
    input = alphabet[j];
    // if it was uppercase, reset it back to uppercase
    if (!lowercase) {
        input = toupper(input);
    }
    // I don't know why this works
    in = &input;
    *out = *in;
}
void Decrypt(const char * in, char * out, int displacement) {
    char input = *in;
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    int characterPosition = -1;
    int lowercase = 0;
    /*
        largely similar code to encryption. didn't want to mess with
        delegating this to another function 
    */
    if (islower(input) > 1) {
        lowercase = 1;
    }
    if (!lowercase) {
        input = tolower(input);
    }
    for (int i= 0; i < 26; i++) {
        if (alphabet[i] == input) {
            characterPosition = i;
            break;
        }
    }
    if (characterPosition == -1) {
        in = &input;
        *out = *in;
        return;
    }
    // set j back to where the encrypted position was. we can reverse 
    // engineer the encryption by just decrementing displacement 
    int j = characterPosition;
    for (int i = displacement; i > 0; i--) {
        j--;
        if (j == -1) {
            j = 25;
        }
    }
    input = alphabet[j];
    if (!lowercase) {
        input = toupper(input);
    }
    // I don't know why this works
    in = &input;
    *out = *in;
}
