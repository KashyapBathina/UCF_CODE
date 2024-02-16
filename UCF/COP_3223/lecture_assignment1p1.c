#include <stdio.h>

/*
    name: Kashyap Bathina
    date: 9/3/23
    purpose: This program takes in five values from the user and then
    outputs the sum, by adding all the numbers and the average, by dividing
    the sum by the number of values--5.
*/

int main(void) {
    // declaring variables, the sum, and the average
    long var1, var2, var3, var4, var5;
    long sum;
    double average;

    // reading in first input and storing it in declared variable
    scanf("%ld", &var1);
    // printing out what the user entered
    printf("You entered: %ld\n", var1);

    // reading in second input and storing it in declared variable
    scanf("%ld", &var2);
    // printing out what the user entered
    printf("You entered: %ld\n", var2);

    // reading in thrid input and storing it in declared variable
    scanf("%ld", &var3);
    // printing out what the user entered
    printf("You entered: %ld\n", var3);

    // reading in fourth input and storing it in declared variable
    scanf("%ld", &var4);
    // printing out what the user entered
    printf("You entered: %ld\n", var4);

    // reading in fifth input and storing it in declared variable
    scanf("%ld", &var5);
    // printing out what the user entered
    printf("You entered: %ld\n", var5);

    // adding all the variables to find the sum
    sum = var1 + var2 + var3 + var4 + var5;
    // dividing the sum of the values by the # of values (5) to find average
    // explicitly casting
    average = (double)sum/5;

    // printing the sum of the values
    printf("The sum of the numbers you entered is: %ld\n", sum);
    // printing the average of the values
    printf("The average is: %.2lf\n", average);

    return 0;
}