#ifndef ADVISING_H
#define ADVISING_H

struct advisingCourseDetails
{
    char courseId [7] ;
    int section ;
};

struct student
{
    char studentId [14] ;
    char name[20] ;
};

void advisingCourse () ;
int advisingMenu () ;
void courseAdd () ;
void courseDrop () ;

#endif


