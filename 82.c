/*
Lab 8.2
Vicki Young
student ID: 20591845
2021.10.14
CS 221-02
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_OF_USERS 10
#define MAX_USER_INPUT_SIZE 100

void addUser(const char*, const char*, int*, char[][NUM_OF_USERS][MAX_USER_INPUT_SIZE]);
int getUserIndex(const char*, char*, int);
void replaceSecondChar(char, const char*, int, char[][NUM_OF_USERS][MAX_USER_INPUT_SIZE]);
void printAll(char*, int);

int main(void) {
    char creds[2][NUM_OF_USERS][MAX_USER_INPUT_SIZE];
    int user_count = 0; //no users in the database yet

    addUser("admin", "s#1Pa5", &user_count, creds);
    addUser("vahab", "fgH!12", &user_count, creds);

    printf("user index of vahab: %d\n", getUserIndex("vahab", creds[0][0], user_count));
    printf("user index of lychee: %d\n", getUserIndex("lychee", creds[0][0], user_count));

    replaceSecondChar('@', "vahab", user_count, creds);

    printf("The total number of users: %d\n", user_count);

    printAll(creds[0][0], user_count);

    return 0;
}
//cannot use [] inside any of the functions

//1. addUser adds a new user with username and password (appends to the end)
void addUser(const char *username, const char *password, int *user_count, char creds[2][NUM_OF_USERS][MAX_USER_INPUT_SIZE])
{
    //*(*creds + *user_count) = *(creds[0] + *user_count) = *(creds[0][user_count]) = creds[0][user_count][0]
    //*(*(creds+1) + *user_count = *(*(creds[1] + *user_count)) = *(creds[1][user_count]) = creds[1][user_count][0]
    strcpy(*(*creds + *user_count), username);
    strcpy(*(*(creds+1) + *user_count), password);
    //FOR TESTING
    //printf("username: %s\n", *(*creds + *user_count));
    //printf("password: %s\n", *(*(creds+1) + *user_count));
    *user_count = *user_count + 1;
    //FOR TESTING
    //printf("user count: %d\n", *user_count);
}

//2. getUserIndex returns the index of the user with given username; if no user with username is found, it returns -1
int getUserIndex(const char *username, char *creds, int user_count)
{
    //creds = creds[0][0]; *creds = creds[0][0][0]
    //creds + (user_index * MAX_USER_INPUT_SIZE) = creds[0][user_index * MAX_USER_INPUT_SIZE]; skip through each username array
    int user_index = 0;   
    while (user_index < user_count) {
        //FOR TESTING
        //printf("creds + user_index: %s\n", creds + user_index * MAX_USER_INPUT_SIZE);
        if (strcmp(username, creds + user_index * MAX_USER_INPUT_SIZE) == 0) { //strcmp() returns 0 if the strings compared are equal; also strcmp() takes pointer, so no need to dereference (use *)
            return user_index;
        } 
        user_index++;
    }
    return -1;
}

//3. replaceSecondChar replaces the second char of a user’s username to new char, only for the user with given username
void replaceSecondChar(char new_char, const char *username, int user_count, char creds[2][NUM_OF_USERS][MAX_USER_INPUT_SIZE]) 
{
    //*(*creds + user_index) = *(creds[0] + user_index) = creds[0][user_index]
    //*(*(*creds + user_index) + 1) = *(*(creds[0] + user_index) + 1) = *(creds[0][user_index] + 1) = creds[0][user_index][1]
    int user_index = 0;   
    while (user_index < user_count) {
        //FOR TESTING
        //printf("current username: %s\n", *(*creds + user_index));
        if (strcmp(username, *(*creds + user_index)) == 0) { //strcmp() returns 0 if the strings compared are equal
            *(*(*creds + user_index) + 1) = new_char;
            //FOR TESTING
            //printf("new username: %s\n", *(*creds + user_index));
        } 
        user_index++;
    }
}

//4. printAll prints all usernames with their corresponding passwords
void printAll(char *creds, int user_count)
{
    //creds = creds[0][0]; *creds = creds[0][0][0]
    //creds + (user_index * MAX_USER_INPUT_SIZE) = creds[0][user_index * MAX_USER_INPUT_SIZE]; skip through each username array
    //(creds + (NUM_OF_USERS * MAX_USER_INPUT_SIZE)) + (user_index * MAX_USER_INPUT_SIZE) = creds[NUM_OF_USERS * MAX_USER_INPUT_SIZE][user_index * MAX_USER_INPUT_SIZE]; first part is to skip past all the arrays of usernames to get down to the array of passwords, second part is to then skip through each password array
    int user_index = 0;   
    while (user_index < user_count) {
        printf("username: %s, password: %s\n", creds + (user_index * MAX_USER_INPUT_SIZE), (creds + (NUM_OF_USERS * MAX_USER_INPUT_SIZE)) + (user_index * MAX_USER_INPUT_SIZE));
        user_index++;
    }
}