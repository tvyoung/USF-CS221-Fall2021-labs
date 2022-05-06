/*
Lab 12.2
Vicki Young
student ID: 20591845
2021.11.16
CS 221-02
*/

#define _XOPEN_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

struct user {
    char username [50];
    char password [256];
    char firstname [50];
    char lastname [50];
    int admin ; //An integer in [0,9]
};

char* cs221Hash(const char* password) {
    return crypt(password, "00");
}

void printUsers(struct user* users, int count) {
    for (int i = 0; i < count; i++) {
        printf("user %d firstname: %s\n", i, (*(users + i)).firstname);
        printf("user %d lastname: %s\n", i, (*(users + i)).lastname);
        printf("user %d username: %s\n", i, (*(users + i)).username);
        printf("user %d password: %s\n", i, (*(users + i)).password);
        printf("user %d password: %d\n", i, (*(users + i)).admin);
    }
}

//QUESTION 1
//reads file credential_file, counts number of lines in file
//creates array based on number of lines, returns pointer, updates count (number of users)
struct user* createUsers(int* count) {
    FILE* fp;
    fp = fopen("credential_file.txt", "r");
    if (fp == NULL) {
        printf("error in opening file.\n");
        exit(1);
    }
    char ch;
    while( (ch = getc(fp)) != EOF) {
        if (ch == '\n') {
            *count = *count + 1;
        }
    }
    struct user* users = (struct user*) calloc(*count, sizeof(struct user));
    if (users == NULL) {
        printf("memory not allocated.\n");
        exit(1);
    }
    fclose(fp);
    return users;
}

//QUESTION 2
//reads file line by line, populates users array with: firstname, lastname, username, password, admin
void populateUsers(void* users) {
    FILE* fp;
    fp = fopen("credential_file.txt", "r");
    if (fp == NULL) {
        printf("error in opening file.\n");
        exit(1); 
    }
    //creates line array to store file input line by line
    char* line = (char*) calloc(1000, sizeof(char));
    //line index (to parse line array)
    int line_index = 0;
    //to read each character in credential_file
    char ch;
    //token to take in line information (username, password, etc)
    char* token;
    //p for pointer to users
    struct user* p = (struct user*) users;
    //user index (for each line of users in struct users)
    int user_index = 0;

    while((ch = getc(fp)) != EOF) {
        //adds each character read in file to line array
        *(line + line_index) = ch;
        //FOR TESTING
        //printf("%c", *(line + line_index));
        //once end of current line in input file has been reached
        if (ch == '\n') {
            line_index = 0;
            //gets the first token
            token = strtok(line, "\t\n");
            //printf("token firstname: %s\n", token);
            while (token != NULL) {
                strcpy((*(p + user_index)).firstname, token);
                token = strtok(NULL, "\t\n");
                //printf("token lastname: %s\n", token);
                strcpy((*(p + user_index)).lastname, token);
                token = strtok(NULL, "\t\n");
                //printf("token username: %s\n", token);
                strcpy((*(p + user_index)).username, token);
                token = strtok(NULL, "\t\n");
                //printf("token password: %s\n", token);
                strcpy((*(p + user_index)).password, token);
                token = strtok(NULL, "\t\n");
                //printf("token admin: %s\n", token);
                (*(p + user_index)).admin = atoi(token);
                token = strtok(NULL, "\t\n");
                //printf("void token: %s\n", token);
                user_index++;
            }
            memset(line, 0, sizeof(line));
            continue;
        }
        line_index++;
    }    
    fclose(fp);
    free(line);
}

//QUESTION 3
//compares hashed input to stored password
//strcmp() will return 0 to indicate str1 and str2 are equal
int checkAdminPassword(char* password, struct user* users, int count) {
    for (int i = 0; i < count; ++i) {
        if (strcmp((users + i)->username, "admin") == 0) {
            //printf("inputed password: %s\n", (users + i)->password);
            //printf("hashed password: %s\n", cs221Hash(password));
            if (strcmp((users + i)->password, cs221Hash(password)) == 0) {
                printf("password matches!\n");
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    return 0;
}

//QUESTION 4
//updates count + returns pointer
struct user* addUser(struct user* users, int* count, char* username, char* password, char* firstname, char* lastname, int admin) {
    struct user* newUsers = (struct user*) realloc(users, (*count) * sizeof(struct user));
    if (newUsers == NULL) {
        printf("memory not properly allocated.\n");
        exit(1);
    }
    strcpy((*(newUsers + *count)).firstname, firstname);
    //printf("newUser firstname: %s\n", (*(newUsers + *count)).firstname);
    strcpy((*(newUsers + *count)).lastname, lastname);
    //printf("newUser lastname: %s\n", (*(newUsers + *count)).lastname);
    strcpy((*(newUsers + *count)).username, username);
    //printf("newUser username: %s\n", (*(newUsers + *count)).username);
    strcpy((*(newUsers + *count)).password, cs221Hash(password));
    //printf("newUser password: %s\n", (*(newUsers + *count)).password);
    (*(newUsers + *count)).admin = admin;
    //printf("newUser firstname: %d\n", (*(newUsers + *count)).admin);

    //increment count (if there were previously 2 users, and a new user was just added, now *count = 3)
    *count = *count + 1;
    //printf("user count: %d\n", *count);
    return newUsers;
}

//QUESTION 5
//writes file user_count 
void saveUsers(struct user* users, int count) {
    FILE* fp;
    fp = fopen("credential_file.txt", "w");
    if (fp == NULL) {
        printf("error in opening file.\n");
        exit(1);
    }
    char tab = '\t';
    printf("reached saveUsers\n");
    for (int i = 0; i < count; i++) {
        fputs((*(users + i)).firstname, fp);
        putc(tab, fp);
        fputs((*(users + i)).lastname, fp);
        putc('\t', fp);
        fputs((*(users + i)).username, fp);
        putc('\t', fp);
        fputs((*(users + i)).password, fp);
        putc('\t', fp);
        /*int num = (*(users + i)).admin;
        char* admin_level = (char*) malloc(sizeof(int));
        if (admin_level == NULL) {
            printf("memory not properly allocated\n");
            exit(1);
        }
        sprintf(admin_level, "%d", num);
        printf("user %d admin_level: %s\n", i, admin_level);
        //fputs(admin, fp);
        free(admin_level);*/
        putc('\n', fp);
    }    
    fclose(fp);
}

int main(void) {    
    int user_count = 0;
    struct user* users = createUsers(&user_count);
    if (users == NULL) {
        return EXIT_FAILURE;
    }
    populateUsers(users);
    printf("Enter admin password to add new users:");
    char entered_admin_password[50];
    scanf("%s", entered_admin_password);
    //printf("hashed entered admin password: %s\n", cs221Hash(entered_admin_password));    
    //printUsers(users, user_count);
    if (checkAdminPassword(entered_admin_password, users, user_count) == 1) {
        struct user new_user;
        printf("Enter username:");
        scanf("%s", new_user.username);
        printf("Enter first name:");
        scanf("%s", new_user.firstname);
        printf("Enter last name:");
        scanf("%s", new_user.lastname);
        printf("Enter password:");
        scanf("%s", new_user.password);
        printf("Enter admin level:");
        scanf("%d", &(new_user.admin));
        users = addUser(users, &user_count, new_user.username, new_user.password, new_user.firstname, new_user.lastname, new_user.admin);
        if (users == NULL) {
            return EXIT_FAILURE;
        }
        printf("user count after adding new user: %d\n", user_count);
    }
    printUsers(users, user_count);
    saveUsers(users, user_count);
    free(users);
    return EXIT_SUCCESS;
}