#ifndef STUDENT_H
#define STUDENT_H

#define NAME_LENGTH 50
#define COURSE_NAME_LENGTH 50

typedef struct {
    int courseId;
    char courseName[COURSE_NAME_LENGTH];
} Course;

typedef struct {
    int id;
    char name[NAME_LENGTH];
    Course* courses;
    int courseCount;
    int courseCapacity;
} Student;

void addStudent(int id, const char* name);
void deleteStudent(int id);
void searchStudent(int id);
void displayAllStudents(void);
void addCourseToStudent(int studentId, int courseId, const char* courseName);

#endif // STUDENT_H
