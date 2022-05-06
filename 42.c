/*
Lab 4.2
Vicki Young
student ID: 20591845
2021.09.16
CS 221-02
*/

#include <stdio.h>
#include <stdbool.h>

bool isDigit(char);
bool isLower(char);
bool isUpper(char);

int main(void) {
    
    //QUESTION 1
    printf("1) Suppose that i and j are variables of type int. What is the type of the expression i / j + 'a'?\n\n");
    int i = 0;
    int j = 1;
    char result = i / j + 'a';
    printf("the expression i / j + 'a' will be of type int.\n");
    printf("i / j will return an int value first, and then that int value is added to 'a'.\n");
    printf("the compiler will then typecast 'a' to an int, specifically 97, and add the values together.\n\n");

    //QUESTION 2
    printf("2) Declare and define three functions isDigit(), isLower() and isUpper().\n");
    printf("   Each function takes a single char as their parameter and returns a bool type indicating\n");
    printf("   if the char is a digit, a lower case character and an upper case character respectively.\n");
    printf("   For isLower() and isUpper(), the function returns false if the character is not a letter.\n");
    printf("   In your main() function, ask the user to enter a character,\n"); 
    printf("   and output the correct statement based on the return value of these functions.\n\n");

    printf("Enter a character: ");
    char ch = getchar();
    
    /*char ch;
    scanf("%c", &ch);*/

    printf("\n");

    if (isDigit(ch)) {
        printf("%c is a digit.\n", ch);
    } else {
        printf("%c is not a digit.\n", ch);
    }

    if (isLower(ch)) {
        printf("%c is a lower case letter.\n", ch);
    } else {
        printf("%c is not a lower case letter.\n", ch);
    }

    if (isUpper(ch)) {
        printf("%c is an upper case letter.\n", ch);
    } else {
        printf("%c is not an upper case letter.\n", ch);
    }

    return 0;
}

bool isDigit(char c) {
    if (c >= 48 && c <= 57) {
        return true;
    } else {
        return false;
    }
}

//returns false if character is not a letter
bool isLower(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    } else {
        return false;
    }
}

//returns false if character is not a letter
bool isUpper(char c) {
    if (c >= 'A' && c <= 'Z') {
        return true;
    } else {
        return false;
    }
}