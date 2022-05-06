/*
Lab 6.1
Vicki Young
student ID: 20591845
2021.09.28
CS 221-02
*/

#include <stdio.h>

void fun(int*);
int sumOfHeadAndTail(int*, int);
int sumOfLargestTwo(int*, int);

int main(void) {
    
    //QUESTION 1
    //output of the following?
    printf("1)\n");

    int r = 20;
    int *p = &r;
    fun(p); //p = address of r
    printf("%d", *p); //after fun(p), p still points to r, hence will still print 20

    printf("\noutput of the program is r's value, 20, since even after fun(p), p still points to r, hence will print 20.\n");


    //QUESTION 2
    //write function sumOfHeadAndTail() which returns sum of the first and last element of arr
    //cannot use [] inside function definition
    //declare int array and initialize it to [1 2 3 4 5 6] in main()
    //pass it to sumOfHeadAndTail() and then print out the sum
    printf("\n2)\n");

    int array[] = {1, 2, 3, 4, 5, 6};
    int arrayLength = sizeof(array) / sizeof(array[0]);

    printf("The sum is %d.\n", sumOfHeadAndTail(array, arrayLength));

    //OPTIONAL QUESTION 3
    //create function sumOfLargestTwo(int* array, int length) which returns sum of the two largest elements in the array
    //assume array has at least two elements
    //for local variables, can only declare pointers of int type
    //in main() function, use array from previous problem and print the sum
    printf("\nOptional 3)\n");
    
    printf("The sum of the largest two is %d.\n", sumOfLargestTwo(array, arrayLength));
    
    return 0;
}

void fun(int *p) { //function fun()'s pointer p = address of r 
    int q = 10;
    p = &q; 
}

int sumOfHeadAndTail(int* arr, int length) {
    //*arr = arr[0] and *(arr+i) = arr[i]
    return *arr + *(arr+(length-1)); 
}

int sumOfLargestTwo(int* array, int length) {
    int *first = array;
    int *second = first+1;
    int *i;

    for (i = array; i < array + length; i++) {
        if (*i > *first) {
            second = first;
            first = i;
            //FOR TESTING printf("*first: %d, *second: %d\n", *first, *second);
        } 
    }
    return *first + *second;
}