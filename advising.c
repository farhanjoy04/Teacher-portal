#include<stdio.h>
#include "advising.h"
#include "forgetpassword.h"

typedef enum
{
    courseAddOption = 1,
    courseDropOption
} advisingOption ;



int advisingMenu()
{
    int choice5 ;

    printf("\n1.Add Course\n")  ;
    printf("2.Drop Course\n") ;

    printf("Enter your choice : ") ;
    scanf("%d",&choice5) ;

    return choice5 ;
}

void advisingCourse ()
{
    int choice6 ;

    choice6 = advisingMenu() ;



    switch (choice6)
    {
    case courseAddOption :
    {
        int j, numberOfCourse ;

        struct student student1 ;

        printf("Enter student id : ") ;
        scanf("%s",&student1.studentId) ;
        printf("Enter student name : ") ;
        scanf("%s",student1.name) ;

        printf("How many course you want to add : ") ;
        scanf("%d",&numberOfCourse) ;

        char fileName[100];
        snprintf(fileName, sizeof(fileName), "%s.txt", student1.studentId);

        FILE *advisingCourseFile = fopen(fileName, "a");
        if (advisingCourseFile == NULL)
        {
            printf("Error opening file");
            return;
        }

        struct advisingCourseDetails *courseAddvise = NULL;

        for (j = 0; j < numberOfCourse; j++)
        {
            courseAddvise = (struct advisingCourseDetails *)malloc(sizeof(struct advisingCourseDetails));
            if (courseAddvise == NULL)
            {
                printf("Error allocating memory");
                break;
            }

            printf("\nEnter course id: ");
            scanf("%s", courseAddvise->courseId);

            printf("Enter section: ");
            scanf("%d", &courseAddvise->section);

            if (fprintf(advisingCourseFile, "%s %d\n",courseAddvise->courseId, courseAddvise->section) < 0)
            {
                printf("Error writing to file");
                free(courseAddvise);
                break;
            }

            printf("Course Added \n");
            free(courseAddvise);
        }

            fclose(advisingCourseFile);
            break ;
    }

    case courseDropOption :
       {
        printf("This is course drop option\n") ;

        char id [10] ;
        char id2 [10] ;
        char studentId [14] ;
        int specificLine=0 , flag=0 , j=2 ;

        printf("Enter stuent id : ") ;
        scanf("%s",&studentId) ;


        char file[100];
        snprintf(file, sizeof(file), "%s.txt",studentId);
        //printf("file name is : %s\n",file) ;

        FILE *drop ;
        drop = fopen(file,"r") ;

        if (drop == NULL)
        {
            printf("The student id is invalid or the student has no course.\n");
            return ;
        }

        printf("Enter course id : ") ;
        scanf("%s",&id) ;

       while(!feof(drop))
       {
           if(j%2 == 0)
        specificLine++ ; //1 2 3

        fscanf(drop,"%s",&id2) ; //cse103 , mat ,  eng

        if ((strcmp(id,id2)==0))
        {
            flag++ ;
            const char *filename = file ;

            char message [] = "Dropped course" ;

            writeStringToSpecificLine(filename, specificLine, message);

                printf("Course dropped done.\n") ;
                break ;
        }
        j++ ;
        }
        if (flag == 0)
        {
                printf("Invalid id .\n") ;
        }
    }

        break ;
       }
    }



