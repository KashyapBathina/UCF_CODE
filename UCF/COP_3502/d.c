/*
recursion:
    body of function calls func itself; however, must make breaking point to prevent infinite loop; ie, can call f2 inside f1 or f1 inside f1
    example: void rec2(int x) {if x==0 return;   rec2(x-1); printf("%d", x)}, prints 1,2,3 . . . bc printf kept in call stack--! data struct stack but a system stack used to
        handle func calls; when funct called, new frame pushed onto call stack that contains info about funct, params, vars, and return adress, when funct returned, frame popped
        in above example, printfs added to stack for each recursion until x==0, then returns and pops backwards until all printfs; other way to visualize, when==0, returns allows
        to go back and finish code, which means past recursion, which was waiting for finish of current can now operate, then prints, which allows past past . . . until all popp
    example: power calculation-b^e: int power(int base, int exponent) { if (exponent==0) return 1;    else return (base*power(base,exponent-1))}, ie, (5,2), return 5 * power(5,1)
        -> (5,1), return 5 power(5,0) -> (5,0) return 1; therfore (5,1) return 5 * 1 = 5 and (5,2) return 5 * 5 = 25
    general struct: 1. if (terminating condition), do final action; else, take 1 step closer to terminating condition by calling recursively on a smaller subproblem
        2. if (!(terminating condition)), take 1 step . . .
    example: decimal to binary: void dectobin(int n) {if (n < 2)  printf("%d", n);    else {dectobin(n/2); printf("%d", n%2);}}
    example: fast exponent--recursive exponent becomes slow w large nums; so exploit law of exponents: 2^8 instead of = 2*2*2 . . . 8 times, 2^8 = 2^4 * 2^4, 2^4 = 2^2 * 2^2, 2^2
        = 2 * 2; 3 mult better than 7; hence b^n = b^n/2 * b^n/2; run time log(n); however, when odd b^n = b^n/2 * b^n/2 * b; code below
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
int powerB(int base, int exp) {
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;
    if (exp%2 == 0) //if exp is even
        return powerB(base*base, exp/2);
    else //if exp is odd
        return powerB(base*base, exp/2) *base;
}


int main() {
    int base, exponent;
    printf("Input base and exponent (2 3): ");
    scanf("%d%d", &base, &exponent);
    printf("%d\n", powerB(base,exponent));

    return 0;
}
*/

void ListPermutations(char str[]);
void RecursivePermute(char str[], int k);
void ExchangeCharacters(char str[], int i, int j);

int main() {
    
    char word[20];
    
    // Let the user enter a word to permute.
    printf("Please enter a word you would like to permute.\n");
    scanf("%s", word);
    
    // Print out the permutations.
    printf("\nHere are the permutations:\n\n");
    ListPermutations(word);
    
    system("PAUSE");
    return 0;
    
}

// Pre-condition: str is a valid C String.
// Post-condition: All permutations of str (assuming all distinct
//                 characters) will be printed.
void ListPermutations(char str[]) {
     
     // Call the appropriate recursive function with the correct
     // parameters.
     RecursivePermute(str, 0);
}

// Pre-condition: str is a valid C String, and k is non-negative and
//                less than or equal to the length of str.
// Post-condition: All of the permutations of str with the first k
//                 characters fixed in their original positions are
//                 printed. Namely, if n is the length of str, then
//                 (n-k)! permutations are printed.
void RecursivePermute(char str[], int k) {
     
     int j;
     
     // Base-case: Since all letters are fixed, we can ONLY print
     // what's stored in str.
     if (k == strlen(str))
         printf("%s\n", str);
         
     else {
          
         // Loop through each possible starting letter for index k,
         // the first index for which we have a choice.
         for (j=k; j<strlen(str); j++) {
         
             // Place the character stored in index j in location k.
             ExchangeCharacters(str, k, j);
             
             // Print out all of the permutations with that character
             // just chosen above fixed. 
             RecursivePermute(str, k+1);
             
             // Put the original character that used to be there back
             // in its place.
             ExchangeCharacters(str, j, k);
         }
     }
}

// Pre-condition: str is a valid C String and i and j are valid indexes
//                to that string.
// Post-condition: The characters at index i and j will be swapped in
//                 str.
void ExchangeCharacters(char str[], int i, int j) {
     
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}