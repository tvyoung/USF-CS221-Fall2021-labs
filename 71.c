/*
Lab 7.1
Vicki Young
student ID: 20591845
2021.10.05
CS 221-02
*/

#include <stdio.h>

#define STRING_LENGTH 30 

void longestCommonString(char*, char*, char*);

int main(void) {

    //QUESTION 1
    printf("1)\n");
    //write a function to find lthe longest common substring of two strings
    //ex. "banana" and "ana" have five common substrings: "ana", "an", "na", "n", "a"
    //longest common substring is "ana"
    //cannot use brackets [] or functions from string.h
    //print out the longest common substring

    char string1[STRING_LENGTH+1];
    char string2[STRING_LENGTH+1];
    char longestCommonStr[STRING_LENGTH+1];

    printf("Enter the first string: ");
    //scanf("%s", string1);
    fgets(string1, sizeof(string1), stdin);
    printf("Enter the second string: ");
    //scanf("%s", string2);
    fgets(string2, sizeof(string2), stdin);
    longestCommonString(string1, string2, longestCommonStr);
    printf("The longest common substring is: %s\n", longestCommonStr);

    return 0;
}

void longestCommonString(char* str1, char* str2, char* result) {
    //count the length of substrings str1 and str2 have in common
    int currentCommonLength = 0;
    //find the length of the largest substring str1 and str2 have common
    int maxCommonLength = 0;
    //pointer for the current character in str2 while looping through it
    char *currentCharacter;
    //pointer which saves the location of the first common character in the largest substring str1 and str2 share; this should be in str2
    char *firstCommonCharacter;

    //while loop which loops through str1
    while (*str1 != '\0') {
        currentCharacter = str2; //currentCharacter = &str2[0] or the first element in str2
        //while loop which loops through str2; we are comparing every element in str2 to a single element in str1 one by one
        while (*currentCharacter != '\0') {
            currentCommonLength = 0;
            //when a character that str1 and str2 have in common is found, begins a while loop to count how many consecutive characters they share (length of the substring)
            //increments str1 and str2 by incrementing currentCommonLength
            while (*(str1+currentCommonLength) == *(currentCharacter+currentCommonLength)) {
                currentCommonLength++;
            }
            //if the length of the current substring is greater than the length of the current longest substring, current substring length becomes the new longest
            if (currentCommonLength > maxCommonLength) {
                maxCommonLength = currentCommonLength;
                //also saves the current character in str2 as the first letter in the longest substring that str1 and str2 share
                firstCommonCharacter = currentCharacter;
            }
            currentCharacter++;
        }
        str1++;
    }

    //adds the longest substring to result (starts from the first common letter that str1 and str2 share, and goes by the longest substring's length)
    for (int i = 0; i < maxCommonLength; i++) {
        *(result+i) = *(firstCommonCharacter+i);
    }
    //to indicate the end of the string in result
    *(result+maxCommonLength) = '\0'; 

}