/*
Lab 5.2
Vicki Young
student ID: 20591845
2021.09.23
CS 221-02
*/

#include <stdio.h>

#define STR_LENGTH 50

int sumOfThree(int, int, int);
int maxInArray(int[], int);

int main(void) {

    //QUESTION 1
    //write a program that calculates and outputs the sum of three int variables, using only pointers
    
    printf("Question 1)\n\n");

    //a) declare three int variables and initialize them to 5, 6, and 12
    int i = 5;
    int j = 6;
    int k = 12;

    //b) declare three int pointers p1, p2, and p3 + initialize them to point to the int variables in a)
    int *p1 = &i;
    int *p2 = &j;
    int *p3 = &k;

    //c) calculate the sum using only p1, p2, and p3
    printf("sum of three ints %d, %d, and %d: %d\n\n", *p1, *p2, *p3, sumOfThree(*p1, *p2, *p3));


    //QUESTION 2
    //in main() function, ask user to enter a string, then modify the second character of the string to '@' and output modified string
    //dont use [] in the statement that manipulates the string

    printf("Question 2)\n\n");

    char str[STR_LENGTH + 1];
    printf("Enter a string: ");
    gets(str);

    char *secondElement = str; //&str[0]
    secondElement++; //&str[1]
    *secondElement = '@';

    printf("The modified string is %s\n\n", str);

    //OPTIONAL PART
    //write a function maxInArray() that takes in two arguments: an int pointer which points to an int[] and an int parameter which is the length of the int[] 
    //returns the maximum integer stored in this array of int
    //in main() function, declare an int[] and initialize it to any int values
    //output the correct maximum number

    printf("OPTIONAL PART, Question 3)\n\n");

    int array[3] = {10, 20, 30};
    int *a = array;
    int length = sizeof(array) / sizeof(array[0]);

    printf("array: ");
    for (int *p = &a[0]; p < &a[length]; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    int max = maxInArray(a, length);
    printf("max of the array: %d\n", max);

    return 0;
}

int sumOfThree(int i1, int i2, int i3) {
    return (i1 + i2 + i3);
}

int maxInArray(int *arrayPointer, int arrayLength) {
    int max = *arrayPointer;

    for (int i = 0; i < arrayLength; i++) {
        if (arrayPointer[i] > max) {
            max = arrayPointer[i];
        }
    }

    return max;
}