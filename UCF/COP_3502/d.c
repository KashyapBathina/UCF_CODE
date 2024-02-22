/*
recursion:
    body of function calls func itself; however, must make breaking point to prevent infinite loop; ie, can call f2 inside f1 or f1 inside f1
    example: void rec2(int x) {if x==0 return;   rec2(x-1); printf("%d", x)}, prints 1,2,3 . . . bc printf kept in call stack: ! data struct stack but a system stack used to
        handle func calls; when funct called, new frame pushed onto call stack that contains info about funct, params, vars, and return adress, when funct returned, frame popped
        in above example, printfs added to stack for each recursion until x==0, then returns and pops backwards until all printfs; other way to visualize, when==0, returns allows
        to go back and finish code, which means past recursion, which was waiting for finish of current can now operate, then prints, which allows past past . . . until all popd
    example: power calculation-b^e: int power(int base, int exponent) { if (exponent==0) return 1;    else return (base*power(base,exponent-1))}, ie, (5,2), return 5 * power(5,1)
        -> (5,1), return 5 power(5,0) -> (5,0) return 1; therfore (5,1) return 5 * 1 = 5 and (5,2) return 5 * 5 = 25
    general struct: 1. if (terminating condition), do final action; else, take 1 step closer to terminating condition by calling recursively on a smaller subproblem
        2. if (!(terminating condition)), take 1 step . . .
    example: decimal to binary: void dectobin(int n) {if (n < 2)  printf("%d", n);    else {dectobin(n/2); printf("%d", n%2);}}
    example: fast exponent--recursive exponent becomes slow w large nums; so exploit law of exponents: 2^8 instead of = 2*2*2 . . . 8 times, 2^8 = 2^4 * 2^4, 2^4 = 2^2 * 2^2, 2^2
        = 2 * 2; 3 mult better than 7; hence b^n = b^n/2 * b^n/2; run time log(n); however, when odd b^n = b^n/2 * b^n/2 * b; code below

permutations:
    possible orderings of items: ie cat: cat, act, tac, cta, atc, tca; to make using recursion: perm statring with c,a, and t: pseudocode is for (each possible starting letter) 
    list all perms startin with that letter; terminating condion when 1 or 0 element, use 0 for this code; input; str && k, (k is 1st k chars that are fixed in orginal position)
    output: all perms of str with 1st k chars fixed are printed-(n-k)!; look below for code; part by part explanation: 
        ListPermutations: charge of starting the process of finding permutations.
        RecursivePermute: starts with the first letter of the word and tries every possible arrangement for the remaining letters by recursively calling itself, each time fixing 
            one more letter in its place until all letters are fixed; whenever it reaches a point where all letters are fixed, it prints out the permutation
            further explan: having trouble visualizing? first for loop is 3 prong for ABC->ABC, BAC, CBA; then each of those three, 2 prong; ABC->ABC,ACB && BAC->BAC,BCA, etc
            the first loop does the 3 initial by swapping first with each lttr (permutation starting with each letter), then from there, do the str, k+1, which does swap for rest
        ExchangeCharacters: swaps two characters in the word; used by RecursivePermute to temporarily change the order of letters while exploring permutations
    permutations 0 to n-1 using helper array and w/o swapping: an arr with partially filled perm; used arr storing which items already partiall filled, int k repr how many items 
    filled in; ie if k=2 and partially filled [2,1,_,_,_] with n=5 ->2,1,3,4,5 or 2,1,3,5,4 . . . etc: code-1. check if k=n, length, if so, then print fulled filled perm; 2. if 
    not, iterate through un-used items placing in k slot and recursively calling func; used array is used to track which item used in partially filled arr-1 in that index if used
    (ie for indexes 2 and 1, value 1), else 0; full code on canvas 
    flood fill: ie, 2d arr representing are where * represents boundry of lake and spaces repr water; input (x,y) where from there we have to fill spaces with ~ characters (water)
    can be blocked, *~~*   *; another example *~~~~~* solution: 1. matrix filled with input from chars; 2. two vars, old (" ") and new ("~"); 3. take starting point(x,y)->(row, colm)
    if you want to go up (x-1,y); down (x+1,y); left (x,y-1); right (x,y+1); 4. try and go in all direction by checking if boundry or out of range matrix, if yes, return to previous 
    or if no, fill up with "~" and go to all directions from that cell
    
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

// permutation code
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
// Post-condition: All permutations of str (assuming all distinct characters) will be printed.
void ListPermutations(char str[]) {
     
     // Call the appropriate recursive function with the correct parameters.
     RecursivePermute(str, 0);
}

// Pre-condition: str is a valid C String, and k is non-negative and less than or equal to the length of str. 
// Post-condition: All of the permutations of str with the first k characters fixed in their original positions are 
// printed. Namely, if n is the length of str, then (n-k)! permutations are printed.
void RecursivePermute(char str[], int k) {
     
     int j;
     
     // Base-case: Since all letters are fixed, we can ONLY print what's stored in str.
     if (k == strlen(str))
         printf("%s\n", str);
         
     else {
          
         // Loop through each possible starting letter for index k, the first index for which we have a choice.
         for (j=k; j<strlen(str); j++) {
         
             // Place the character stored in index j in location k.
             ExchangeCharacters(str, k, j);
             
             // Print out all of the permutations with that character just chosen above fixed. 
             RecursivePermute(str, k+1);
             
             // Put the original character that used to be there back in its place.
             ExchangeCharacters(str, j, k);
         }
     }
}

// Pre-condition: str is a valid C String and i and j are valid indexes to that string.
// Post-condition: The characters at index i and j will be swapped in str. 
void ExchangeCharacters(char str[], int i, int j) {
     
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}