#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    name: Kashyap Bathina
    date: 2/17/24
    purpose: 
*/


void ListPermutations(char str[]);
void RecursivePermute(char str[], int k);
void ExchangeCharacters(char str[], int i, int j);



int main(int argc, char *argv[])
{
    /* the first command-line parameter is in argv[1] 
       (arg[0] is the name of the program) */
    FILE *fp = fopen(argv[1], "r"); /* "r" = open for reading */

    if (fp == NULL) 
        printf("The file you gave either does not exist, or is spelled incorrectly\n");
    
    else {
        int n;
        int p;

        fscanf(fp, " %d\n", &n);
        fscanf(fp, " %d\n", &p);


        while (n-->0) {

        }

        while (p-->0) {

        }

        
        printf("hello, worldA\n");
    }

    fclose(fp);
}



int main () {
    // 
    printf("hello, worldA\n");

    return 0;
}
