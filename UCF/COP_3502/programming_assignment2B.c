#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*
    name: Kashyap Bathina
    date: 2/17/24
    program: wheretositb
*/

// defining constants for our hate arrays and name string to declare size
#define nameSize 20
#define hateArraySize 10

// creating a struct that includes string name, an array of strings that the person hates, the # people they hate, and the value of their popcorn (have or ! have)
typedef struct person { 
    char name[nameSize];
    char hate[nameSize][hateArraySize];
    int numhate;
    int popcorn;
} person;

// declaring size of people and the ammount of pairs who don't want to sit next to each other, then declaring and initializng number of valid perm to 0
int n, p;
int foundValidPermutation = 0;

// declaring our functions
void ListPermutations(person people_attending[]);
void RecursivePermute(person people_attending[], int k);
void ExchangeCharacters(person people_attending[], int i, int j);
void validOrder(person people_attending[]);


// main code
int main(int argc, char *argv[]) {
    // opening file from command line input
    /* the first command-line parameter is in argv[1]; (arg[0] is the name of the program) */
    FILE *fp = fopen(argv[1], "r"); /* "r" = open for reading */
    
    // checking if file given is existent
    if (fp == NULL) 
        printf("The file you gave either does not exist, or is spelled incorrectly\n");
    
    else {       
        // if file, then scanning in # of people and the numbers of pairs who don't want to sit next to each other 
        fscanf(fp, "%d", &n);
        fscanf(fp, "%d", &p);
        
        // creating an array of people struct of size n
        person people_attending[n];
        
        // for n times, scanning in each person and their subsequent popcorn value (0 if ! popcorn, 1 else)
        for (int i=0; i<n; i++) {
            fscanf(fp, " %s", people_attending[i].name);
            fscanf(fp, "%d ", &people_attending[i].popcorn);

            // initializing the hate array (people the person hates) to null and then setting the number of people they hate to 0
            for (int j=0; j<10;j++) {
                strcpy(people_attending[i].hate[j], "\0");
            }
            people_attending[i].numhate = 0;
        }

        // for each pair of people who dislike each other
        while (p-->0) {
            // scanning in the names
            char person1[20] = "\0";
            char person2[20] = "\0";
            fscanf(fp, "%s ", person1);
            fscanf(fp, "%s ", person2);

            // for n times, 
            for (int i=0; i<n;i++) {
                // finding person1's name, then adding their hate array by copying person2's name into the array of index currenthate then incrementing currenthate
                if ((strcmp(people_attending[i].name, person1)==0)) {
                    strcpy(people_attending[i].hate[people_attending[i].numhate], person2);
                    people_attending[i].numhate++;
                }
                // finding person2's name, then adding their hate array by copying person1's name into the array of index currenthate then incrementing currenthate
                if ((strcmp(people_attending[i].name, person2)==0)) {
                    strcpy(people_attending[i].hate[people_attending[i].numhate], person1);
                    people_attending[i].numhate++;
                }
            }
        }
        
        // passing in the array of people attending from the input into the permutation function
        ListPermutations(people_attending);        
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
    // when we find a valid permutation, return (because we only want the first valid permutation for alphabetical ordering)
    if (foundValidPermutation) 
        return;

    // Base-case: Since all letters are fixed, we can ONLY print what's stored in str.
    int j;
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
    // swapping person struct at indexes i and j
    person temp = people_attending[i];
    people_attending[i] = people_attending[j];
    people_attending[j] = temp;
}

// function that checks if the permutation given from the RecursivePermute funct is valid
void validOrder(person people_attending[]) {
    // for i=1;n-1, (because we don't want to accces wrong array index)
    for (int i=1;i<n-1;i++) {
        // check if value of popcorn at index == 0
        if (people_attending[i].popcorn == 0) {
            // if both the first two people attending have popcorn value 0, special case and return
            if (i == 1 && people_attending[i - 1].popcorn == 0) 
                return; // Not a valid order, return without incrementing count

            // if both the last two people attending have popcorn value 0, special case and return
            if (i == n - 2  && people_attending[i + 1].popcorn == 0)
                return;

            // if not special cases, then pocorn arrangement not valid if three people in row have no popcorn
            if (people_attending[i - 1].popcorn == 0 && people_attending[i + 1].popcorn == 0)
                return;
        }   

        // check if next to hate by iterating over each hatearray per person for each person in the permutation-2
        for (int j=0;j<people_attending[i].numhate;j++) {
            // if you compare for each perosn-2, who they hate (iterating over each hate in the array) and the people next to (i-1 and i+1) and they are equal, then returning since not valid
            if ((strcmp(people_attending[i].hate[j], people_attending[i-1].name)==0) || (strcmp(people_attending[i].hate[j], people_attending[i+1].name)==0))
                return;
        }
    }

    // if reach this point, then the permutation is valid; since we only need 1st valid perm, indicate that we have found the first valid perm
    foundValidPermutation = 1;
    for (int i=0; i<n; i++) {
        // for that valid permutation, printing each person's name
        printf("%s\n", people_attending[i].name);
    }
}
