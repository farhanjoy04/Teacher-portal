#include <stdio.h>
#include <stdlib.h>
#include "signup.h"
#include "login.h"
#include "forgetpassword.h"
#include "course.h"

typedef enum
{
    signupOption = 1,
    loginOption ,
    forgetPassOption
} options ;



int mainMenu ()
{
    unsigned int  choice1 ;

    printf("\n") ;
    printf("1.Sign Up\n") ;
    printf("2.Login\n") ;
    printf("3.Forget Password\n") ;

    printf("\nEnter a number : ") ;
    scanf("%u",&choice1) ;

    return choice1 ;
}

int main()
{
    struct person faculty1 ;
    unsigned int choice2 ;

    choice2 = mainMenu () ;

    switch (choice2)
       {
       case signupOption :
          {
              inputInformation(faculty1);
              break ;
          }
       case loginOption :
          {
            checklogin() ;

            break ;
          }
       case forgetPassOption :
          {
            forgetPassword () ;
            break ;
          }
      default :
           {
               printf("Please enter the right number.\n") ;
               break ;
           }

    }

    getch() ;
    return 0 ;
}
