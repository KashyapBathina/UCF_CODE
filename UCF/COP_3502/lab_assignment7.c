#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element{
    int value;
    int number_times_swapped;
} element;

void bubbleSort(int arr[], int n) { 
    int i, j, total_count = 0;
    element elements[n], temp;

    for (int i = 0; i < 9; i++) {
        elements[i].value = arr[i];
        elements[i].number_times_swapped = 0;
    }

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (elements[j].value > elements[j+1].value) {//then swap
                temp=elements[j];
                elements[j]=elements[j+1];
                elements[j+1]=temp;

                elements[j].number_times_swapped++;
                elements[j+1].number_times_swapped++;
                total_count++;
            }
        }
    }

    for (int i=0; i<9; i++) {
        printf("%d: %d times swapped\n", elements[i].value, elements[i].number_times_swapped);
    }
    printf("total # of swaps: %d\n", total_count);
    printf("\n");
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, total_count =0;
    element elements[n], temp;

    for (int i = 0; i < 9; i++) {
        elements[i].value = arr[i];
        elements[i].number_times_swapped = 0;
    }

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (elements[j].value < elements[min_idx].value)
                min_idx = j;
        
        if (min_idx!=i) {
            // Swap the found minimum element with the first element
            temp = elements[i];
            elements[i] = elements[min_idx];
            elements[min_idx] = temp;
            
            elements[i].number_times_swapped++;
            elements[min_idx].number_times_swapped++;
            total_count++;
        }
    }

    for (int i=0; i<9; i++) {
        printf("%d: %d times swapped\n", elements[i].value, elements[i].number_times_swapped);
    }
    printf("total # of swaps: %d\n", total_count);
    printf("\n");

}


int main() {
    int array1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    printf("Bubble Sort: \n");
    printf("array1: \n");
    bubbleSort(array1, 9);
    printf("array2: \n");
    bubbleSort(array2, 9);

    printf("Selection Sort: \n");
    printf("array1: \n");
    selectionSort(array1, 9);
    printf("array2: \n");
    selectionSort(array2, 9);

}

