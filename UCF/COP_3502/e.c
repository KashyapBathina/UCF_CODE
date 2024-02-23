/*
algorithm analysis:
    various algorithms, but how to judge efficiency or speed; can't find exact timing since machine dependent, so use order notation to approximate; called big-o approximation
    assume each statement and comparison takes constant amount of time; performance depends on input, or size of input n; notated O(n) or order of n; 
        most significant growth: 1. only consider most influence as n gets larger 2. eliminate constant fatcors; ie for 4n^2+3n+1, as n gets large, 3n+1 accounts for very litte, 
        so ignore it and the 4 in 4n^2, so O(n^2) steps; ie 42n^2(12n^6) = O(n^8); ie f(n) = 75n*logn-a = O(n*logn); order funcions: if g(n) = n^2; and f(n) = 4n^2 . . ., then
        for f(n) = O(n^2); since g(n) = n^2 -> O(g(n));
        constants: f(n) is O(g(n)) iff exists c and N, such that f(n) <= c*g(n) for all n>=N; ie, for above ex, f(n) <= c*g(n) -> 4n^2+3n+1 <= 5n^2; however, only true for large 
        n values, ie , for n=1, 4n^2+3n+1=8 and 5n^2=5; however, for values n>=5, 5n^2 greater and statement true; c*g(n) is upper bound, worse possible case
        code example: for (n/2) {do funct}; for (n*n) {do funct}; since not nested loop, order = n/2 + n^2 -> O(n^2); if nested, O(n^3); O(1) just means constant operations
        code example: while(n>0) {printf; n=n/2) because halfing n each time, logn
        common orders (slowest -> fastest): 1 (constant), logn(logarithmic), n(linear), nlogn(poly-log), n^2(quadratic), n^3(cubic), 2^n(exponential), n!(factorial)
        math problems: prgA runs in O(n^2), for input 4, runs in 10 ms, what is run time for input 16; remember O-time not exact, so T(n) = c*f(n); then T(n) = c*n^2; so
            T(4) = c*4^2 = 10 -> c=10/16; so T(16) = (10/16) * 16^2 = 10 * 16 = 160 ms; (note for solving: log_2(16) = log_2(2^4) = 4)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char name[50];
    
    scanf("%s", name);
    printf("Hello, %s", name);
}