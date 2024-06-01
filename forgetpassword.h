#ifndef FORGETPASSWORD_H
#define FORGETPASSWORD_H

#define MAX_LENGTH 256
#define MAX_LINES 1000

void forgetPassword () ;
void writeToFile(char lines[MAX_LINES][MAX_LENGTH], int totalLines, const char *filename) ;
void writeStringToSpecificLine(const char *filename, int lineNumber, const char *newString) ;


#endif



