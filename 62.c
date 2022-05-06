/*
Lab 6.2
Vicki Young
student ID: 20591845
2021.09.30
CS 221-02
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


void reverseArray(int*, const int);
void foo(int*, const int*, const int*, int* const);
bool toss();

int main(void) {

    //QUESTION 1
    printf("1)\n");
    //complete while loop in reverseArray function using 5 or less statements 
    //cannot use [] inside function

    int array[15];
    int len = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < len; i++) {
        array[i] = i;
    } //array is [0, 1, 2, . . .  14]
    reverseArray(array, len);
    printf("The reversed array is ");
    for (int i = 0; i < len; ++i) {
        printf("%d", array[i]);
        if (i != len - 1) {
            printf(", ");
        } else {
            printf(".\n");
        }
    } //output array should be 14, 13, 12, . . . 0


    //QUESTION 2
    printf("\n2)\n");
    printf("Answered through commenting in code\n");
    //identify which statements in the following code will result in error
    //use commenting and compiler to confirm 

    int x[3] = {1, 2, 3};
    foo (x , x, x, x);


    //QUESTION 3
    printf("\n3)\n");
    srand(time(0)); //set the seed of the pseudorandom number generator using current time
    char quit = ' ';
    scanf(" %c", &quit);
    while(quit != 'n') //quit if user enters n
    {
        if (toss()) {
            printf("It's a head.\n");
        } else {
            printf("It's a tail.\n");
        }
        printf("Keep tossing? (y/n)\n");
        scanf(" %c", &quit);
    }


    return 0;
}

//takes an int array and reverses it
void reverseArray(int* arr, const int length) {
    int* pStart = arr;
    int* pEnd = arr + length - 1;
    int temp = *pStart; //declared temp variable
    while (pStart < pEnd) {
        *pStart = *pEnd; //1
        pStart++; //2
        *pEnd = temp; //3
        pEnd--; //4
        temp = *pStart; //5
    }
}

void foo(int* ptr, const int* ptr1, const int* ptr2, int* const ptr3) { //const pointer vs pointing to a const
    ptr1++;
    //ptr1[0] = 1; //this statement causes issue because ptr1 has been declared a const pointer of type int, and it is read-only. we cannot change the value of the variable that ptr1 points to
    printf("%d", ptr1[0]);
    ptr2++;
    //ptr2[0] = 3; //this statement causes issue because ptr2 has been declared a const pointer of type int, and it is read-only. we cannot change the value of the variable that ptr2 points to
    printf("%d", ptr2[0]);
    //ptr3++; //this statement causes issue because ptr3 has been declared a pointer with a const int value, meaning we cannot change the address that ptr3 has/the variable ptr3 points to 
    ptr3[0] = 3;
    printf("%d", ptr3[0]);
}

//coin toss function which takes no arguments
//returns true or false randomly every time is called
bool toss() {
    //int random = rand() % 2;
    //FOR TESTING: printf("%d\n", random);
    if (rand() % 2 == 0) { //rand() % 2 should give a number 0 or 1
        return true;
    } else {
        return false;
    }
}