

#ifndef SIGNUP_H
#define SIGNUP_H
#define SIZE 20

struct dateOfBirth
{
    int date ;
    int month ;
    int year ;
};

struct person
{
    char name [SIZE] ;
    char id [25] ;
    char email [SIZE] ;
    char password [SIZE] ;
    char position [10] ;
    char department [SIZE] ;
    char mobileNumber [SIZE] ;
    struct dateOfBirth dob ; // structure of structure type
};

void inputInformation (struct person faculty ) ;
void displayInformation (struct person faculty2) ;
void idGenerate (struct person *faculty3) ;
void readAllLines(char *filename, struct person *faculty4) ;


#endif

