/*
Lab 8.1
Vicki Young
student ID: 20591845
2021.10.05
CS 221-02
*/

#include <stdio.h>

#define TEXT_LENGTH 50
#define TRUE 0
#define FALSE 1

int recursiveStrcmp(const char*, const char*);
void recursiveIntToString(int, const char*, int);

int main(void) {

    //QUESTION 1
    //write function recursiveStrcmp() where returns 0 when contents of two strings str1 and str2 are the same; otherwise returns 1
    //cannot use square brackets, string library functions, or loops
    //function can only traverse char array recursively

    char text1[TEXT_LENGTH];
    char text2[TEXT_LENGTH];
    printf("Enter first string: ");
    fgets(text1, sizeof(text1), stdin);
    printf("Enter second string: ");
    fgets(text2, sizeof(text2), stdin);

    if (recursiveStrcmp(text1, text2) == TRUE) {
        printf("contents of the two given strings are the same\n");
    } else {
        printf("contents of the two given strings are not the same\n");
    }

    //QUESTION 2
    //write a function recursiveIntToString() where it takes an integer n as a specificed base and converts it to a string; stores string in result
    //cannot use square brackets or loops
    //can assume that n > 0, and base <= 10
    //result may be in a reversed order
    

    return 0;
}

int recursiveStrcmp(const char* str1, const char* str2) {

    //if str1[i] is equal to str2[i]
    if (*str1 == *str2) {
        //and if it is the end of str1 and str2, then the contents of str1 and str2 should be the same; return 0
        if (*str1 == '\0' && *str2 == '\0') {
            return 0;
        //otherwise, return recursiveStrcmp(str1(i+1), str2(i+1)); as in, move the pointers up to point to the next elements in each string array    
        } else {
            return recursiveStrcmp(++str1, ++str2);
        }
    //else if there was any instance of str1[i] not equal to str2[i], immediately returns 1
    } else {
        return 1;
    }
}

void recursiveIntToString(int n, const char* result, int base) {

}