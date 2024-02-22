/*
algorithm analysis:
    various algorithms, but how to judge efficiency or speed; can't find exact timing since machine dependent, so use order notation to approximate; called big-o approximation
    assume each statement and comparison takes constant amount of time; performance depends on input, or size of input n; notated O(n) or order of n; 
        most significant growth: 1. only consider most influence as n gets larger 2. eliminate constant fatcors; ie for 4n^2+3n+1, as n gets large, 3n+1 accounts for very litte, 
        so ignore it and the 4 in 4n^2, so O(n^2) steps; ie 42n^2(12n^6) = O(n^8); ie f(n) = 75n*logn-a = O(n*logn)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char name[50];
    
    scanf("%s", name);
    printf("Hello, %s", name);
}