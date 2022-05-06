/*
Lab 12.2
Vicki Young
student ID: 20591845
2021.11.16
CS 221-02
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct user {
    char username [50];
    char password [50];
    int admin;
};

//QUESTION 2
//dynamically creates an array of struct user with given length; returns pointer to this array
struct user* createUsers(int max_number_of_users) {
    struct user* users = (struct user*) calloc(max_number_of_users, sizeof(struct user));
    //check that memory was allocated properly
    if (users == NULL) {
        printf("memory not allocated\n");
        exit(1);
    }
    return users;
}

//QUESTION 3
//initializes given number of users usernames to "default", passwords to "default", and admins to 0
void initUsers(void* users, int max_number_of_users) {
    struct user* p = (struct user*) users;
    for (int i = 0; i < max_number_of_users; i++) {
        //p->username is the same as (*p).username
        //(p + i)->username is the same as (*(p + i)).username
        strcpy((*(p + i)).username, "default");
        strcpy((*(p + i)).password, "default");
        (*(p + i)).admin = 0;
    }
}

//QUESTION 4
//adds a new user + updates userCount
void addUser1(struct user* users, char* username, char* password, int admin, int* count) {
    strcpy((*(users + *count)).username, username);
    strcpy((*(users + *count)).password, password);
    (*(users + *count)).admin = admin;
    //updates userCount after, since first user should be at users[0]
    *count = *count + 1;
}

//QUESTION 5
//adds new user by passing struct newUser + updates userCount
void addUser2(struct user* users, struct user* newUser, int* count) {
    memcpy((users + (*count)), newUser, sizeof(struct user));
    //updates userCount after, since first user should be at users[0], and second user should be at users[1], and so forth
    *count = *count + 1;
}

//QUESTION 6
//prints out username and password for given number of users
void printUser(struct user* users, int max_number_of_users) {
    for (int i = 0; i < max_number_of_users; i++) {
        //users->username is the same as (*users).username
        //(users + i)->username is the same as (*(users + i)).username
        printf("username%d: %s\n", i, (*(users + i)).username);
        printf("password%d: %s\n", i, (*(users + i)).password);
    }
}

struct user** findAllAdmins(struct user* users, int max_number_of_users, int* adminCount) {
    // Your code goes here
    return 0;
}

int main(void) {
    struct user* users = createUsers(10);
    if (users == NULL) {
        return EXIT_FAILURE;
    }

    int userCount = 0;
    initUsers(users, 10);
    addUser1(users, "admin", "s#1Pa5", 1, &userCount);
    addUser1(users, "vahab", "fgH!12", 0, &userCount);
    //struct user u1 = {"usf", "gA24?m", 2};
    struct user u1;
    u1.admin = 2;
    strcpy(u1.username, "usf");
    strcpy(u1.password, "gA24?m");
    //QUESTION 1
    //fixed compiler error: give addUser2() the address of u1
    addUser2(users, &u1, &userCount);
    printUser(users, userCount);
    free(users);
    return EXIT_SUCCESS;
}