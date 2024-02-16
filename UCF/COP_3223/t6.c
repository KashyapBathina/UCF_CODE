#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*------------module 6------------------------------------------------------------------------------------------------------------*/

/*
    Important: array is a pointer to an int, that is why int arr[]; printf(arr) only results in memory adress, can do printf(*arr) to go to first element
    or just do arr[i];
    Important: when making array int A[10] = { 3,2,1,0,4}, when you don't initialize ALL elements, can do some, rest elements are initialized to zero
    Array:data struc that holds series of variables with the same datatype
        Gen Struct: type var name[size];
                    char colors[5];
                    start array with 0 and goes to 4
                    int numbers[10];
                    numbers[0] = 1;
                    numbers[1] = 2;
        Common Mistakes:
                    1. Out of bounds: happends when your index into array is invalid when yu try to reference it
                    2. Tyring to assign an entire array a valus such as test_scores=7;
                    3. Not recognizing the differnece between an array index and values stored in a particular index
*/

/*
int main() {
    int index, test_scores[50];

    printf("Please enter 5 test scores: ");
    for (index=0;index<5;index++) {
        scanf("%d", &test_scores[index]);
    }

    printf("Here are the scores in revers order: ");
    for (index=4;index>=0;index--) {
        printf("%d ", test_scores[index]);
    }

}
*/

/*
#define SIZE 10
int main() {
    int index, temp, numbers[SIZE];

    srand(time(0));

    for (index=0;index<SIZE;index++) {
        numbers[index] = rand() % 100;
    }

    printf("Original values: ");
    for (index=0;index<SIZE;index++) {
        printf("%d ", numbers[index]);
    }

    printf("\n");
    for (index=0;index<SIZE/2;index++) {
        temp = numbers[index];
        numbers[index] = numbers[SIZE-1-index];
        numbers[SIZE-1-index] = temp;
    }

    printf("Array in reverse: ");
        for (index=0;index<SIZE;index++) {
        printf("%d ", numbers[index]);
    }
    printf("\n");

}
*/

#define SIZE 10
int main()
{
    int index, temp, numbers[SIZE];
    srand(time(0));

    for (index = 0; index < SIZE; index++)
    {
        numbers[index] = rand() % 100;
    }

    printf("Original values: ");
    for (index = 0; index < SIZE; index++)
    {
        printf("%d ", numbers[index]);
    }
    printf("\n");

    int val;
    printf("What is the # you want to serach for: ");
    scanf("%d", &val);

    int found = 0;
    for (index = 0; index < SIZE; index++)
    {
        if (numbers[index] == val)
        {
            found = 1;
        }
    }

    if (found == 1)
        printf("%d was in the array\n", val);
    else
        printf("%d was NOT in the array\n", val);

    return 0;
}
