#ifndef STUDENT_H
#define STUDENT_H

#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Student;

void addStudent(int id, const char* name);
void deleteStudent(int id);
void searchStudent(int id);
void displayAllStudents(void);

#endif // STUDENT_H