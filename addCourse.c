#ifndef STUDENT_H
#define STUDENT_H

#define NAME_LENGTH 50
#define COURSE_CODE_LENGTH 20
#define COURSE_NAME_LENGTH 50

typedef struct {
    char code[COURSE_CODE_LENGTH];
    char name[COURSE_NAME_LENGTH];
    // Add more fields as needed (e.g., instructor, credits, etc.)
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
void addCourseToStudent(int studentId, const char* courseCode, const char* courseName);

#endif // STUDENT_H
