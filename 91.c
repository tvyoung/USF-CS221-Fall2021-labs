/*
Lab 9.1 
Vicki Young
student ID: 20591845
2021.10.21
CS 221-02
*/

//QUESTION 1

#include <stdio.h>

int getSecond(void*);
int mod2(int*);
char theLastChar(void*);

int main(void) {
    int intArr[5] = {20, 4, 10, 6, 5};
    printf("The second int is %d.\n", getSecond((void*)intArr));
    
    unsigned int i = 0xfffffff1;
    printf("%u mod 2 is %d.\n", i, mod2((int*)&i));
    
    char str [] = "USF";
    printf("The last character is %c.\n", theLastChar((void*)str));
}

//1. complete the following three functions

//Returns the second int in intArr
int getSecond(void* intArr) {
    return *((int*)intArr + 1);
}

//Returns i mod 2 , i is an unsigned int
int mod2(int* i) {
    return *((unsigned int*)i);
}

//Returns the last character in str
char theLastChar(void* str) {
    //find length of str
    int length = 0;
    while (*((char*)str + length) != '\0') {
        length++;
    }
    return *((char*)str + length-1);
}