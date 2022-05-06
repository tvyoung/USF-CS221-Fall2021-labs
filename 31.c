/*
Lab 3.1
Vicki Young
student ID: 20591845+
2021.09.08
CS 221-02
*/

#include <stdio.h>
#include <time.h>
#include <math.h>

int main() 
{
    clock_t start, end;
    float seconds;

    //TESTING FOR UNSIGNED SHORT
    start = clock();
    const unsigned short correct_hu_password = 55555;
    unsigned long guessed_password = 0;
    //%hu for unsigned short; %u for unsigned int; %lu for unsigned long
    /*
    largest value = 2 to the power of (number of  variable type's bytes * 8 to get bits) - 1
    unsigned short = 2 bytes, unsigned int = 2 bytes, unsigned long = 4 bytes
    unsigned long upper_bound = (pow(2, (sizeof(correct_password) * 8))) - 1;
    */
    unsigned short upper_hu_bound = -1;
    printf("tested password is unsigned short. largest value: %hu\n", upper_hu_bound);

    for (guessed_password = 0; guessed_password <= upper_hu_bound; guessed_password++) 
    {
        if (guessed_password == correct_hu_password)
        {
            printf("Password cracked: %hu. Login successful.\n", correct_hu_password);
            break;
        } 

    }
    end = clock();
    seconds = (float) (end - start) / CLOCKS_PER_SEC;
    printf("start = %d, end = %f\n", start, end);
    printf("It took %f seconds to complete this.\n\n", seconds);


    //TESTING FOR UNSIGNED INT
    start = clock();
    const unsigned int correct_u_password = -1;
    unsigned int upper_u_bound = -1;
    printf("tested password is unsigned int. largest value: %u\n", upper_u_bound);

    for (guessed_password = 0; guessed_password <= upper_u_bound; guessed_password++) 
    {
        if (guessed_password == correct_u_password)
        {
            printf("Password cracked: %u. Login successful.\n", correct_u_password);
            break;
        } 

    }
    end = clock();
    seconds = (float) (end - start) / CLOCKS_PER_SEC;
    printf("start = %d, end = %f\n", start, end);
    printf("It took %f seconds to complete this.\n\n", seconds);


    //TESTING FOR UNSIGNED LONG
    start = clock();
    const unsigned long correct_lu_password = -1;
    unsigned long upper_lu_bound = -1;
    printf("tested password is unsigned long. largest value: %lu\n", upper_lu_bound);

    for (guessed_password = 0; guessed_password <= upper_lu_bound; guessed_password++) 
    {
        if (guessed_password == correct_lu_password)
        {
            printf("Password cracked: %lu. Login successful.\n", correct_lu_password);
            break;
        } 

    }
    end = clock();
    seconds = (float) (end - start) / CLOCKS_PER_SEC;
    printf("start = %d, end = %f\n", start, end);
    printf("It took %f seconds to complete this.\n\n", seconds);

    printf("for guessing passwords, my program takes the longest to crack the password for an unsigned long when it is an unsigned long's largest possible value. specifically, %lu.\n", upper_lu_bound);
    
    return 0;
}