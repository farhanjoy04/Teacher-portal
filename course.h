#ifndef COURSE_H
#define COURSE_H
#define SIZE4 20

struct courseDetails
{
    char courseId [7] ;
    char courseName [SIZE4] ;
    float credit ;
};

void facultyCourses (char techerId2 []) ;
int facultyCoursesMenu () ;
void viewCourse () ;
void addCourse () ;

#endif


