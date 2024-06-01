#include<stdio.h>
#include<string.h>
#include "signup.h"

void readAllLines(char *filename, struct person *faculty4)
 {
    checkLabel :
    printf("Enter your password: ");
    gets(faculty4->password);

    faculty4->password[strcspn(faculty4->password, "\n")] = '\0';

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    char line[20];
    int lineNumber = 0;
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        lineNumber++;

        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, faculty4->password) == 0)
        {
            printf("This password is not valid\n") ;
            printf("Please enter another password .\n") ;

            goto checkLabel ;
        }
    }

    fclose(file);
}

void idGenerate (struct person *faculty3)
{
    char id[25];

    int min_range = 1;
    int max_range = 100;
    int randomNum;

    srand(time(0)) ;
    randomNum = min_range + rand() % (max_range - min_range + 1);

    sprintf(id, "2022#%d", randomNum);

    strcpy(faculty3->id,id) ;
}

void inputInformation (struct person faculty)
{    char problem [2] ;
     gets(problem) ;

    printf("\nEnter your name with out sapce (Ali_Haidar) : ") ;
    gets(faculty.name) ;
    printf("Enter your email : ") ;
    gets(faculty.email) ;

    idGenerate(&faculty) ;

    const char *filename = "signFile.txt";
    readAllLines(filename,&faculty) ;

    printf("Enter your position : ") ;
    scanf("%s",&faculty.position) ;
    printf("Enter your department : ") ;
    scanf("%s",&faculty.department) ;
    printf("Enter your mobile number : ") ;
    scanf("%s",&faculty.mobileNumber) ;
    printf("Enter date of birth (date month year) : ") ;
    scanf("%d %d %d",&faculty.dob.date,&faculty.dob.month,&faculty.dob.year) ;

    printf("Your unique id will be provided \n");
    printf("Thank You Sir\n") ;

    FILE *signFile;
    signFile = fopen("signFile.txt", "a");
    if (signFile != NULL)
    {
        fprintf(signFile, "%s\n%s\n%s\n%s\n",faculty.id, faculty.password, faculty.name, faculty.email);
        fprintf(signFile, "%s\n%s\n%s\n%d-%d-%d\n", faculty.position, faculty.department, faculty.mobileNumber, faculty.dob.date, faculty.dob.month, faculty.dob.year);
        fclose(signFile);
    }
    else
    {
        printf("Error opening file for writing.\n");
    }


    void (*ptrInputInformation)(struct person) ;//  function pointer declare
    ptrInputInformation = &displayInformation ; // function pointer initialize
    (*ptrInputInformation)(faculty) ; // function call
}

void displayInformation (struct person faculty2)
{
    printf("\n\nName : %s\n",faculty2.name) ;
    printf("Id : %s\n",faculty2.id) ;
    printf("Email : %s\n",faculty2.email) ;
    printf("Position : %s\n",faculty2.position) ;
    printf("Department : %s\n",faculty2.department) ;
    printf("Mobile number : %s\n",faculty2.mobileNumber) ;
    printf("Date of birth : %d-%d-%d",faculty2.dob.date,faculty2.dob.month,faculty2.dob.year) ;
}


