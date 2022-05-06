/*
Lab 9.1
Vicki Young
student ID: 20591845
2021.10.21
CS 221-02
*/

//QUESTION 2

#include <stdio.h>
#include <stdlib.h>

//program addnumbers.c takes many command line arguments as the user wishes
//then calculates and outputs the sum of all numbers entered
//can assume that the user input only contains integers
//function atoi() converts string representation of an integral number to an int value
//build and run addnumbers.c on a Unix lab machine

int main(int argc, char* argv[]) {
    int sum = 0;
    for (int i = 0; i < argc; i++) {
        //FOR TESTING
        //printf("%d\n", atoi(argv[i]));
        sum = sum + atoi(argv[i]);
    }
    printf("%d", sum);

    return 0;
}