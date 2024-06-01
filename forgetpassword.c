#include<stdio.h>
#include<string.h>
#include "forgetpassword.h"

#define SIZE3 20
#define MAX_LENGTH 256
#define MAX_LINES 1000

void writeToFile(char lines[MAX_LINES][MAX_LENGTH], int totalLines, const char *filename)
 {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing");
        return;
    }

    for (int i = 0; i < totalLines; i++) {
        fputs(lines[i], file);
    }

    fclose(file);
}

void writeStringToSpecificLine(const char *filename, int lineNumber, const char *newString)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file for reading");
        return;
    }

    char lines[MAX_LINES][MAX_LENGTH];
    int totalLines = 0;

    // Read all lines from the file
    while (fgets(lines[totalLines], sizeof(lines[totalLines]), file))
    {
        totalLines++;
    }
    fclose(file);

    // Check if the specified line number is valid
    if (lineNumber <= 0 || lineNumber > totalLines)
    {
        printf("Invalid line number: %d\n", lineNumber);
        return;
    }

    // Replace the specified line with the new string
    snprintf(lines[lineNumber - 1], MAX_LENGTH, "%s\n", newString);

    // Write the modified contents back to the file
    writeToFile(lines, totalLines, filename);
}

void forgetPassword ()
{
    char userId [SIZE3] ;
    char userId2 [SIZE3] ;
    int randNo , specificLine=1 ;
    char randNo2 [SIZE3] ;
    char password [SIZE3] ;
    char rePassword [SIZE3] ;

    char problem3 [2] ;
    gets(problem3) ;

    printf("Enter your user id : ") ;
    gets(userId) ;

    FILE *forgetFile ;
    forgetFile = fopen("signFile.txt","r") ;

    while(!feof(forgetFile))
    {
        specificLine++ ;
        fscanf(forgetFile,"%s",&userId2) ;

        //printf("%s\n",userId) ;
        //printf("%s\n",userId2) ;

        if ((strcmp(userId2,userId)==0))
        {
            const char *filename = "signFile.txt";

            printf("Enter a new password : ") ;
            gets(password) ;
            printf("Enter again the password : ");
            gets(rePassword) ;

            if (strcmp(password,rePassword) == 0)
            {
                writeStringToSpecificLine(filename, specificLine , password);

                printf("Password changed \n") ;
            }
        }
    }


}


