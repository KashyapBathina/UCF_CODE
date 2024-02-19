#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*
    name: Kashyap Bathina
    date: 2/17/24
    purpose: 
*/
typedef struct person { 
    char name[20];
    char hate[20][10];
    int numhate;
    int popcorn;
} person;

int n, p;
int numOfValidOrders = 0;

void ListPermutations(person people_attending[]);
void RecursivePermute(person people_attending[], int k);
void ExchangeCharacters(person people_attending[], int i, int j);
void validOrder(person people_attending[]);




int main(int argc, char *argv[]) {
    /* the first command-line parameter is in argv[1] 
       (arg[0] is the name of the program) */
    FILE *fp = fopen(argv[1], "r"); /* "r" = open for reading */
    
    if (fp == NULL) 
        printf("The file you gave either does not exist, or is spelled incorrectly\n");
    
    else {        
        fscanf(fp, "%d", &n);
        fscanf(fp, "%d", &p);
        
        person people_attending[n];

        for (int i=0; i<n; i++) {
            fscanf(fp, " %s", people_attending[i].name);
            fscanf(fp, "%d ", &people_attending[i].popcorn);
            for (int j=0; j<10;j++) {
                strcpy(people_attending[i].hate[j], "none");
            }
            people_attending[i].numhate = 0;
        }

        while (p-->0) {
            char person1[20] = "\0";
            char person2[20] = "\0";
            fscanf(fp, "%s ", person1);
            fscanf(fp, "%s ", person2);

            for (int i=0; i<n;i++) {
                if ((strcmp(people_attending[i].name, person1)==0)) {
                    strcpy(people_attending[i].hate[people_attending[i].numhate], person2);
                    people_attending[i].numhate++;
                }
                if ((strcmp(people_attending[i].name, person2)==0)) {
                    strcpy(people_attending[i].hate[people_attending[i].numhate], person1);
                    people_attending[i].numhate++;
                }
            }
        }
        

        ListPermutations(people_attending);
        printf("%d", numOfValidOrders);
        
    }

    fclose(fp);
}



// Pre-condition: str is a valid C String.
// Post-condition: All permutations of str (assuming all distinct characters) will be printed.
void ListPermutations(person people_attending[]) {
     
     // Call the appropriate recursive function with the correct parameters.
     RecursivePermute(people_attending, 0);
}

// Pre-condition: str is a valid C String, and k is non-negative and less than or equal to the length of str. 
// Post-condition: All of the permutations of str with the first k characters fixed in their original positions are 
// printed. Namely, if n is the length of str, then (n-k)! permutations are printed.
void RecursivePermute(person people_attending[], int k) {
     
    int j;
     
    // Base-case: Since all letters are fixed, we can ONLY print what's stored in str.
    if (k == n) {
        validOrder(people_attending);
    }
         
     else {
          
        // Loop through each possible starting letter for index k, the first index for which we have a choice.
        for (j=k; j<n; j++) {
         
            // Place the character stored in index j in location k.
            ExchangeCharacters(people_attending, k, j);
             
            // Print out all of the permutations with that character just chosen above fixed. 
            RecursivePermute(people_attending, k+1);
             
            // Put the original character that used to be there back in its place.
            ExchangeCharacters(people_attending, j, k);
        }
    }
}

// Pre-condition: str is a valid C String and i and j are valid indexes to that string.
// Post-condition: The characters at index i and j will be swapped in str. 
void ExchangeCharacters(person people_attending[], int i, int j) {
    person temp = people_attending[i];
    people_attending[i] = people_attending[j];
    people_attending[j] = temp;
}

void validOrder(person people_attending[]) {
    for (int i=1;i<n-1;i++) {
        // check if next to popcorn
        if (people_attending[i].popcorn == 0) {
            if (i == 1 && people_attending[i - 1].popcorn == 0) 
                return; // Not a valid order, return without incrementing count
        
            if (i == n - 2  && people_attending[i + 1].popcorn == 0)
                return;

            if (people_attending[i - 1].popcorn == 0 && people_attending[i + 1].popcorn == 0)
                return;
        }   

        // check if next to hate
        for (int j=0;j<people_attending[i].numhate;j++) {
            if ((strcmp(people_attending[i].hate[j], people_attending[i-1].name)==0) || (strcmp(people_attending[i].hate[j], people_attending[i+1].name)==0))
                return;
        }
    }

    numOfValidOrders++;
}
