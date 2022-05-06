/*
Lab 4.1
Vicki Young
student ID: 20591845
2021.09.14
CS 221-02
*/

#include <stdio.h>

int calculateSum(int array[]) {
    int sum = array[0] + array[2];
    return sum;
}

int sumOfSubarray(int arr[], int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += arr[i];
    }
    return sum;
}

/*int largestContiguousSum(int array[], int size) {
    int maxSum = array[0]; 
    int currentMax = array[0];
    int currentIndex = 0;

    for (int i = 0; i < size; i++) {
        currentMax += sumOfSubarray(array, i, currentIndex+1);
        if (maxSum < currentMax) {
            maxSum = currentMax;
        }
    }
}*/

int main(void) {

    //QUESTION 1
    printf("1) Write a function that takes an int array and calculates the sum of first and third element. Assume the array has at least three elements.\n\n");

    int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array1Size = sizeof(array1) / sizeof(array1[0]);

    printf("array1: ");
    for (int i = 0; i < array1Size; i++) {
        printf("%d ", array1[i]);
    }

    printf("\n\nsum of the first and third element in array1: %d", calculateSum(array1));

    //QUESTION 2
    printf("\n\n2) Modify your main function so that it checks if the array has at least three elements first before calling the function. You should calculate the size of the array using the sizeof keyword in your main() function. If the array has less than three elements, your program should print a message instead and terminates.\n\n");

    int array2[] = {1, 2};
    int array2Size = sizeof(array2) / sizeof(array2[0]);

    printf("array2: ");
    for (int i = 0; i < array2Size; i++) {
        printf("%d ", array2[i]);
    }

    //if size of given array is at least 3, then call calculateSum function
    if (array2Size >= 3) {
        printf("\n\nsum of the first and third element in array2: %d\n", calculateSum(array2));
    //else, print message
    } else {
        printf("\n\nERROR: array2 is not three or more elements long.\n");
    }

    //QUESTION 3
    printf("\n3) Write a function sumOfSubarray(int arr[], int start, int end) which returns the sum of all elements in the subarray starting with index start until index end.\n\n");

    int array3[] = {1, -3, 2, 9, -2, 10};
    int array3Size = sizeof(array3) / sizeof(array3[0]);

    printf("array3: ");
    for (int i = 0; i < array3Size; i++) {
        printf("%d ", array3[i]);
    }

    printf("\n\nsum of elements from index 1 to 3: %d\n", sumOfSubarray(array3, 1, 3));
    printf("sum of elements from index 0 to 1: %d\n", sumOfSubarray(array3, 0, 1));

    //OPTIONAL
    printf("\n(Optional) Write a C program to find the sum of contiguous subarray within an int array which has the largest sum. A subarray may have a length from 1 to the length of the array. For example, if the array is [1, -3, 2, 9, -2, 10], then the subarray with the largest sum is [2, 9, -2, 10], so your program should print the sum of the subarray which is 19 Hint: Your function should call sumOfSubarray().\n\n");

    //array2 reverse order
    int array4[] = {10, -2, 9, 2, -3, 1};
    int array4Size = sizeof(array4) / sizeof(array4[0]);

    printf("array4: ");
    for (int i = 0; i < array4Size; i++) {
        printf("%d ", array4[i]);
    }

    return 0;
}