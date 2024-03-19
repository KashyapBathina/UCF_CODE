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
        code example: while(n>0) {printf; n=n/2) because halfing n each time, logn; the reason why is this: after 1st time, n/2, then for second iteration, n/4, 3rd=n/8=n/2^3; 
            noting this pattern, after k iterarations, n set to n/2^k and alorithim ends when n/2^k=1 (b/c 1/2=0 which is terminating condition); since k is total number of iter
            at-ions, we want to solve for k -> k=logn (this is the run time for binary since this program is essentialy what binary search does)
            binary search: So, during the iteration, we update our low or high based on the condition of whether the # we are looking for is above or below the currennt mid- we 
            want to check the data in that part of the array and we want new mid; the terminating condition is if (low<=high), this is because if at point where low=high=mid, b/c
            there is no index that has the # we are searching, then if # is lower the mid, than h=mid-1=h-1 (terminate); if # higher, l=mid+1=l+1 (terminate)
        common orders (slowest -> fastest): 1 (constant), logn(logarithmic), n(linear), nlogn(poly-log), n^2(quadratic), n^3(cubic), 2^n(exponential), n!(factorial)
        math problems: prgA runs in O(n^2), for input 4, runs in 10 ms, what is run time for input 16; remember O-time not exact, so T(n) = c*f(n); then T(n) = c*n^2; so
            T(4) = c*4^2 = 10 -> c=10/16; so T(16) = (10/16) * 16^2 = 10 * 16 = 160 ms; (note for solving: log_2(16) = log_2(2^4) = 4)
        code example: int i&j=0; while (i<n) {while (j<n && arr[i][j]==1) { j++} } i++; might assume since while loop inside while loop, O(n^2), but instead O(n), b/c in first 
            loop outer, run the inner loop until exhaust n times (since no reset), after that, inner can no longer run so just O(n+n) = O(n); if put j=0 bfore inner, then n^2

recursive relations:
	to find o(n) for recursive functions: cannot just eyeball like before, must use summations to find an equation that defines a sequence recursively to find big O of recursive
	code example: int fact (int n) { if(n=1) return 1; else return (n*fact(n-1))}, simple factorial code; where T(n) is # operations, total num operations for fact with any input
		is the num arithmetic op (-, *) plus the num of operations to execute n-1 times, in other words T(n) = T(n-1) + 2 and T(1) = 1; however, we don't actually know # operats
		b/c T(n-1) unknow, therefore must find closed form by eliminating functions T(...)'s from RHS, thus reduce T(n-1) till we get T(1) b/c that is the only we value we know,
		thus we just plug n-1 into the n's until get a pattern (no need to go to T(1) necc): 
			eq-1) T(n) = T(n-1) + 2     eq-2) T(n-1) = T(n-2) + 2, so T(n) = T()     eq-3) T(n-2) = T(n-3) + 2; then plugging back into T(n) = T(n-3) + 2*3, hence pattern is 
			T(n) = T(n-k) + 2*k; to solve now, remember T(1) = 1, so we want n-k=1 -> k=n-1, plugging back in -> T(n) = T(n-n+1) + 2*(n-1) = T(1) + 2n-2 = 2n-1, hence O(n)
	code example: in power(int x, int n) {if n=0, return 1    if n=1, return x    if n is even, return power(x*x, n/2)     if n is odd, return power(x*x,n/2)*x}, to calc x^n,
		when computing time complexity, we assume worst case, so when odd do three arithmetic operations, so assume always odd -> T(n) = T(n/2) + 3 and T(1) = 1, then to find the
		closed form: 
			eq-1) T(n) = T(n/2) + 3     eq-2) T(n/2) = T(n/4) + 3     eq-3) T(n/4) = T(n/8) + 3, then subsituting T(n) = T(n/8) + 2*3 or T(n) = T(n/2^k) + 3*k, we want n/2^k=1, as
			thats the only T(..) we know, so n/2^k = 1 and n=2^k, we also want k, so log(n) = log(2^k) -> log(n) = k, so T(n) = T(2^k/2^k) + 3*log(n) = 1 + 3logn, so O(logn)
	note: we consider arithmetic operations here while we don't in the algorithm analysis b/c for loops, the num arithmetic operations is constant, so just O(kn) -> O(n) and just
	depends on and scales with n; for recursion, the num arithmetic operations per call depends on the n and so the operations varies, thus must consider recursiv calls and operat
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int search(int numbers[], int low, int high, int value) 
{
	if (low<=high) {
		int mid = (low+high)/2;
		if (value<numbers[mid])
			return search(numbers, low, mid-1, value);
		else if (value>numbers[mid])
			return search(numbers, mid+1, high, value);
		else return mid;
	}
	return -1;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}