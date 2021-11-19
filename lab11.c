/*  ==============================
    Course: CS 1050H
    Semester: Fall 2021
    Date: 11/12/2021
    Lab: Lab 11
    Author: Matthew Marlow
    Pawprint: mm7f5
    ===============================
*/
#include <stdio.h>
#include <string.h>
#include "fight.h"
int main(int argc, char * argv[])
{
    // get command line args
    char creature1[20];
    char creature2[20];
    strcpy(creature1, argv[1]);
    strcpy(creature2, argv[2]);

    FILE * fp;
    char name[256];
    int ac1 = -1, hp1, hitbonus1;
    char name1[30], attack1damage1[15], attack2damage1[15];
    int ac2 = -1, hp2, hitbonus2;
    char name2[30], attack1damage2[15], attack2damage2[15];
    // open file
    fp = fopen("monster.csv","r");
    if (NULL !=fp) {
        // read in header
        fgets(name, 255,fp);
        name[255] = '\0';
        /*
            I was doing some research for this and stumbled upon something that said that
            this condition is never correct. Is this true?
        */
        while (!feof(fp)) {
            if (fp && !feof(fp)) {
                // storage for initial file read
                char buffer[100];
                char name[30], attack1damage[15], attack2damage[15];
                int ac, hp, hitbonus;
                fgets(buffer, 100, fp); // get line of string
                sscanf(buffer, "%d, %d, %d, %[^,], %[^,], %s", &ac, &hp, &hitbonus, attack1damage, attack2damage, name); // break down into chunks using sscanf
                printf("%s\n", name);
                if (0 == strncmp(name, creature1, 5)) { // if first 5 characters are the same, then this is the first creature
                    strcpy(name1, name);
                    strcpy(attack1damage1, attack1damage);
                    strcpy(attack2damage1, attack2damage);
                    ac1 = ac, hp1 = hp, hitbonus1 = hitbonus;
                }
                if (0 == strncmp(name, creature2, 10)) { // if first 10 characters are the same, then this is the second creature
                    // if the name is correct, everything else must be
                    strcpy(name2, name);
                    strcpy(attack1damage2, attack1damage);
                    strcpy(attack2damage2, attack2damage);
                    ac2 = ac, hp2 = hp, hitbonus2 = hitbonus;
                }
            }
        }
        // close file
        fclose(fp);
        // ensure we found both creatures before running fight
        if (ac1 != -1 && ac2 != -1) {
            Fight(name1, ac1, hp1, hitbonus1, attack1damage1, attack2damage1,name2, ac2, hp2, hitbonus2, attack1damage2, attack2damage2);
        }
    }
    else {
        printf("An error occured. Could not read file.\n");
    }
        
}
