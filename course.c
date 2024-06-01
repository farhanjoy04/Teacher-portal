#include <stdio.h>
#include "course.h"
#include "login.h"

typedef enum
{
    viewCourseOption=1 ,
    AddCourseOption
} facultyCoursesOption ;

int facultyCoursesMenu ()
{
   int choice3 ;

   printf("\n1.View Course")  ;
   printf("\n2.Add Course\n") ;

   printf("\nEnter your choice : ") ;
   scanf("%d",&choice3) ;

   return choice3 ;
}

void sortArray (struct courseDetails arr [] , int len) //Bubble Sort
{
    int i , j ;
    struct courseDetails temp ;

    for (i=0 ; i<len-1 ; i++)
    {
        for (j=0 ; j<len-1 ; j++)
        {
            if (arr[j].credit > arr[j+1].credit)
            {
                temp = arr[j] ;
                arr[j] = arr[j+1] ;
                arr[j+1] = temp ;
            }
        }
    }
}

void viewCourse (char techerId3 [])
{
    FILE *facultyViewCourseFile ;
    facultyViewCourseFile = fopen(strcat(techerId3,".txt"),"r") ;

    /*struct courseDetails course2 ;*/

    if (facultyViewCourseFile == NULL)
    {
        printf("The faculty has no course\n") ;
        return ;
    }



    struct courseDetails course2 [10] ;
    int i = 0 , j ;

    while(!feof(facultyViewCourseFile))
    {
        /*fscanf(facultyViewCourseFile,"%s %s %f",&course2.courseId,&course2.courseName,&course2.credit) ;*/

        /*printf("Course id : %s\n",course2.courseId) ;
        printf("Coures name : %s\n",course2.courseName) ;
        printf("Course credit : %f\n",course2.credit) ;*/

        fscanf(facultyViewCourseFile,"%s %s %f",&course2[i].courseId,&course2[i].courseName,&course2[i].credit) ;

        i++ ;
    }

    sortArray(course2,i-1) ;

    for (j=0 ; j<i-1 ; j++)
    {
        printf("\nCourse id : %s\n",course2[j].courseId) ;
        printf("Coures name : %s\n",course2[j].courseName) ;
        printf("Course credit : %f\n",course2[j].credit) ;
    }
}

void addCourse (char techerId4 [])
{
    int numberOfCourse  , i ;
    struct courseDetails *course = NULL ; //pointer for linkedlist

    printf("How many course you want to add : ") ;
    scanf("%d",&numberOfCourse) ;

    FILE *facultyAddCourseFile ;
    facultyAddCourseFile = fopen(strcat(techerId4,".txt"),"a") ;


    for (i=0 ; i<numberOfCourse ; i++) // using linkedlist
    {
        course = (struct courseDetails*) malloc (sizeof(struct courseDetails)) ;

        printf("\nEnter course id : ") ;
        scanf("%s",&course->courseId) ;

        char problem3 [2] ;
        gets(problem3) ;

        printf("Enter course name : ") ;
        gets(course->courseName) ;
        printf("Enter credit of the course : ");
        scanf("%f",&course->credit) ;

        /*printf("Course id :- %s\n",course->courseId) ;
        printf("Course name : %s\n",course->courseName) ;
        printf("Course credit : %f\n",course->credit) ;
        printf("For faculty : %s\n",techerId4) ;*/

        //printf("File name is : %s\n",strcat(techerId4,".txt")) ;

        if (facultyAddCourseFile == NULL)
        {
            printf("File can not open\n") ;
        }
        else
            fprintf(facultyAddCourseFile,"%s %s %f\n",course->courseId,course->courseName,course->credit) ;

        printf("Course Added \n") ;
    }
}

void facultyCourses (char techerId2 [])
{
    int choice4 ;

    int (*ptrFacultyCoursesMenu)() ;
    ptrFacultyCoursesMenu = &facultyCoursesMenu ;
    choice4 = (*ptrFacultyCoursesMenu)() ;

    switch(choice4)
    {
    case viewCourseOption :
        {
            //printf("This is view course\n") ;
            viewCourse(techerId2) ;
            break ;
        }
    case AddCourseOption :
        {
            //printf("This is add course\n") ;
            addCourse(techerId2) ;
            break ;
        }
    default :
        {
            printf("Please enter correct command \n") ;
        }
    }
}


