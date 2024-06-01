#include<stdio.h>
#include "login.h"
#include "signup.h"
#include "course.h"
#include "advising.h"

struct login teacher ;

typedef enum
{
    profile = 1,
    manageCourse ,
    advising ,
    logout
}afterLoginOptions ;

void afterLoginMenu ()
{
    int choice2 ;

    for (;;){

    printf("\n\n") ;
    printf("\n1.Show profile \n") ;
    printf("2.Manage Course\n") ;
    printf("3.Student Advising\n") ;
    printf("4.Logout\n") ;

    printf("\nEnter a option : ") ;
    scanf("%d",&choice2) ;

    switch (choice2)
    {
    case profile :
        {
            char buffer[100] ;
            char dob [100] ;
            //printf("This is profile\n") ;
            //printf("%s",teacher.id);

            struct person faculty3  ;

            FILE *profileFile ;

            profileFile = fopen("signFile.txt", "r");

            while (!feof(profileFile))
            {
                fgets(buffer, sizeof(buffer), profileFile);

                buffer[strcspn(buffer, "\n")] = '\0'; //remove the new line

                 if (strcmp(buffer,teacher.id) == 0)
                 {
                     int counter =1 ;

                    // while (counter<8)
                    // {
                         //fgets(buffer2, sizeof(buffer2), profileFile);
                         fscanf(profileFile,"%s %s %s %s %s %s %s",&faculty3.name,&faculty3.id,&faculty3.password,&faculty3.email,&faculty3.position,&faculty3.department,&dob) ;
                         printf("User ID : %s\nPassword : %s\nName : %s\nEmail : %s\nPosition : %s\nDepartment : %s\nMobile Number : %s\nDate of birth : %s%s",teacher.id,faculty3.name,faculty3.id,faculty3.password,faculty3.email,faculty3.position,faculty3.department,faculty3.mobileNumber,dob) ;
                         //counter++ ;
                    // }
                 }
            }

            break ;
        }
    case manageCourse :
        {
            //printf("This is manageCourse\n") ;
            char techerId [20] ;
            strcpy(techerId , teacher.id) ;
            facultyCourses(techerId) ;
            break;
        }
    case advising :
        {
            advisingCourse () ;
            break ;
        }
    case logout :
        {
            return 0 ;
        }
    default :
        {
            printf("Please enter correct option.\n") ;
        }
    }
}
}

void checklogin()
{
    char userId [20] ;
    char pass [20] ;
    int flag = 0 ;

    char problem [2] ;
    gets(problem) ;

Again :

    printf("Enter your user id : ") ;
    gets(teacher.id) ;
    printf("Enter your password : ");
    gets(teacher.password) ;

    FILE *loginFile ;
    loginFile = fopen("signFile.txt","r") ;

    while(!feof(loginFile))
    {


        fscanf(loginFile,"%s %s",&userId,&pass) ;

        //printf("%s %s\n",userId,pass) ;

        if ((strcmp(teacher.id,userId)==0) && strcmp(teacher.password,pass)==0)
        {
            flag++ ;
            printf("\nLogin succsessfully\n") ;
            //printf("%s %s\n",userId,pass) ;

            void (*ptrAfterLoginMenu)() ;
            ptrAfterLoginMenu = &afterLoginMenu ;
            (*ptrAfterLoginMenu)() ; //function call using function pointer .

            break;
        }
    }

    if (flag == 0)
    {
        printf("Not Login.Enter correct user id or password.\n") ;

        goto Again ;
    }


}


