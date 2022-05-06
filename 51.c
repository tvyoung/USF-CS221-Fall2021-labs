/*
Lab 5.1
Vicki Young
student ID: 20591845
2021.09.21
CS 221-02
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TEXT_LENGTH 50

bool doesContainDigit(char[]);
bool doesContainOneDigit(char[]);
int stringToInt(char[]);

int main(void) {
    
    //QUESTION 1
    //write function doesContainDigit() which takes in a string as an argument (can use strlen())
    //returns true if contains at least one digit (called parsing); returns false otherwise
    //in main() function, ask user to enter a string. output correct statement based on return value of function

    printf("Question 1)\n\n");
    char text[TEXT_LENGTH+1];
    
    printf("Enter a string: ");
    gets(text);
    if (doesContainDigit(text)) {
        printf("The string contains digits.\n");
    } else {
        printf("The string does not contain any digit.\n");
    }

    printf("\nEnter another string: ");
    gets(text);
    if (doesContainDigit(text)) {
        printf("The string contains digits.\n");
    } else {
        printf("The string does not contain any digit.\n");
    }

    //QUESTION 2
    //write function doesContainOneDigit() which takes in string as argument
    //returns true if and only if string contains only one number

    printf("\nQuestion 2)\n\n");

    printf("Enter a string: ");
    gets(text);

    //checks if string contains digits
    if (doesContainDigit(text)) {
        printf("The string contains digits.\n");
    } else {
        printf("The string does not contain any digit.\n");
    }
    //checks if string contains only one digit
    if (doesContainOneDigit(text)) {
        printf("The string contains only one digit.\n");
    } else {
        printf("The string does not contain only one digit.\n");
    }

    //OPTIONAL
    //write function stringToInt() which takes in a string containing only digits as an argument
    //returns an integer the string represents
    //in main() function ask user to enter a string. then output the correct number
    
    printf("\nOptional part, Question 3)\n\n");
    printf("Enter a string: ");
    gets(text);
    printf("The number is: %d.", stringToInt(text));

    return 0;
}

//returns true if contains at least one digit (called parsing); returns false otherwise
bool doesContainDigit(char str[]) {    
    for (int i = 0; str[i] != '\0'; i++) {
        //if str[i] contains a number 0 to 9 (ASCII)
        if (str[i] >= 48 && str[i] <= 57) {
            return true;
        }
    }
    return false;
}

//returns true if and only if string contains only one number; returns false otherwise
bool doesContainOneDigit(char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        //if str[i] contains a number 0 to 9, increase count
        if (str[i] >= '0' && str[i] <= '9') {
            count++;
        }
    } 
    //if count is not equal to 1 (as in, str[] contains no numbers, or contains more than one number), returns false
    //otherwise returns true
    if (count != 1) {
        return false;
    } else {
        return true;
    }
}

//takes in a string containing only digits as an argument, returns an integer the string represents
int stringToInt(char str[]) {
    int sign;
    int startingPoint = 0;
    int num = 0;

    //if first element in string number is negative sign, meaning number is negative, sign becomes -1
    if (str[0] == '-') {
        sign = -1;
    }
    //if sign is -1, starting point for for loop becomes 1
    if (sign == -1) {
        startingPoint = 1;
    }

    for (int i = startingPoint; str[i] != '\0'; i++) {
        //num *= 10 is for each digit converted to int
        //str[i] - '0' is for the char int ASCII value - 48 (0 ASCII value)
        //for example: if str[i] is 1, ASCII value of 1 is 49, and ASCII value of 0 is 48. so 49 - 48 = 1
        num = num * 10 + str[i] - '0';
    }
    
    //if the string number was negative, then num becomes negative
    if (sign == -1) {
        num = -num;
    }

    return num;
}