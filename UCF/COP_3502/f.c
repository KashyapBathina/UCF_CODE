/*
sorting algorithms:
    select sort: O(n^2); during first iteration, go through all n items and find smallest (can be largest too) and put that in first position, during second iteration go thru n-1 
        and find min and place in second position and repeat, at 2nd iter no need to to check index 0 since already correct, therfore run time total = n + (n-1) + (n-2) ... + 1; so
        in total = n(n+1)/2 b/c of summation, (n^2+n)/2, so just simplifies to O(n^2)
    bubble sort: O(n^2); also called sinking sort; always compare consecutive elements going left to right, whenever out of place ie 2 1 instead of 1 2, swap so at the end of one
        iteration, max element in last spot and repeat this n times; on each pass, one more max element put in place; in 1st iteration, goes through n-1, second goes through n-2,
        therefore since starts at n-1 instead of n like select sort, total = (n-1) + (n-2) ... = (considering previous just plug in n-1 for n) (n-1)((n-1+1)/2) = n(n-1)/2 -> O(n^2)
    insertion sort: O(n^2); based on sliding technique like bookshelf, if first 2 books out of order 4 3, remove 2nd and slide 1st (4) to right and insert removed to first (3), then 
        if 3rd book out of order 3 4 2, then remove that book and slide 1st and 2nd (3 and 4) to the right and insert removed (2) to the front; general form 1. remove next unsorted
        2. slide sorted books to right until right spot for removed and 3. insert removed book to new position; then from i=1 to n-1, at i=1, 1 iter, at i=2, 2 iter, so complexity 
        total = 1 + ... n-1, so know (from bubble) = n(n-1)/2 -> O(n^2); 2x fast as bubble and less swaps; builds sorted by transferring one at a time
    merge sort:
*/











#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    printf("hello, world");

    return 0;
}