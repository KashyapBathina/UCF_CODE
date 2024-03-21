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
    merge sort: O(n*logn); divides and conqueuers the lists: if list size 0 or 1, already sorted; else 1. divide list into 2 sublists approx n/2 each 2. recursvly sort each sublist 
        by calling mergesort on each list 3. merge the 2 sublists back into one sorted list; what 2. does is split each of the 2 initial sublist into more 4 lists and this is done
        again until split into smaller and smaller until size 1 or 0, then merge these into larger sorted lists; beneifts: small list fewer steps to merge two lists sorted as oppsd
        to 2 unsorted b/c if sorted, only need to traverse each list once, hence merge sort is mergsort(arr, l, r) {1. find middle point to split m=(l+r)/2     2. call mergsort for
        first half mergesort(arr,l,m)      3. call mergesort for second half mergsort(arr,m+1,r)     4. merge the halfs merge(arr,l,m,r)}; a key func is the merge funct where given
        2 lists, merge into 1 sorted by keeping track of smallest val in each arr not placed in new larger arr and compare the smallest of each arr as since ordered, each of those
        must be the smallest of both arrs that are left and place the smallest of these in the new ordered larger arr (like the sort merge for linked lists) and then adjust the new 
        smallest value for each arr by indexing, and continue until all placed; to find time complexity: T(n) = T(step 2--merge 1 half) + T(step 3--merge 2 half) + T(step 4--merge)
        step 4 is only O(n) b/c since merged, only looking through each n/2 arr once; T(n) = 2T(n/2) + n; just recursive relation: T(n/2) = 2T(n/4) + n/2 -> T(n) = 2(2T(n/4) + n/2)
        + n = 4t(n/4) + 2n -> generalized to T(n) = 2^k T(n/2^k) + kn, know T(1) = 1, so n=2^k and k = logn -> T(n) = 2^logn T(1) + logn*n = n + logn*n -> O(n*logn)
    quick sort: best and average case O(n*logn) & worst case O(n^2); picks element as pivot, partions the given arr around the pivot point, many diff pivot points-1st, last, rand,
        median; process 1. select one pivot, compare all other elements in arr with select element 2. of element smaller, put on left side 3. if greater put on right; after one run
        know pivot in right spot as all items larger right and smaller left;however each left and right still need to be sorted; thus full funct 1) partition arr with respect pivot
        2) sort left side using quick sort 3) sort right using quick sort; quick sort is recursive funct that ends when arr size 1; thus quicksort(arr,low,high) { if(low<high) {k = 
        partition(k, low, high)   quicksort(arr,low,k-1)   quicksort(arr,k+1,high) }}; partition: if pivot 1st element, start 2 counters index 1 and index max, advance left until 
        val greater than pivot, advance right counter (max) until val less than pivot then swap these elements, then repeat and stop if counters cross over each other then swap the 
        right counter with the pivot; this gets partition with all less below pivot and all greater above pivot noting those above and below might now be sorted, next repeat recurv 
        for left and right side by taking pivots and repeating; for code analaysis, depends on how good parition is (if it divides equally or not) and best case is middle and worst 
        case is 1st or last element ordered, so analyze best-average case which is same as merge O(n*logn); if unlucky and not repeatedly choosing smallest/largest, not dividing at 
        all, so comparing n-1 then n-2 so eseentially just as insertion O(n^2); this program uses in-place concept as insted of making alloc new arr, just overwrites it
    quick select: best and average case O(n) & worst case O(n^2); not sorting algorithm, but to find k-th smallest element in unordered set; like quick sort but don't need to 
        actually sort entire arr; do same partition by picking pivot but now only recur for the part that contains the k-th smallest element (if partition index>k, recur left else
        right); best case o(n) if choose k-th element as pivot; worst case O(n^2) if look through all n on first, then n-1 ... (select sort); average case remove half each time so
        n + n/2 + n/4 ... = 2n - 1 = O(n)   
*/











#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    printf("hello, world");

    return 0;
}