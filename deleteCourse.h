#ifndef DELETECOURSE_H
#define DELETECOURSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int courseID;
    char courseName[100];
} Course;

extern Course* courses;
extern int courseCount;

void delete_course(int id);

#endif // DELETECOURSE_H
