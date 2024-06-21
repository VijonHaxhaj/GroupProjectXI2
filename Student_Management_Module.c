#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define COURSE_NAME_LENGTH 50

// Structure for Course
typedef struct {
    int courseId;
    char courseName[COURSE_NAME_LENGTH];
} Course;

// Structure for Student
typedef struct {
    int id;
    char name[NAME_LENGTH];
    Course* courses;
    int courseCount;
    int courseCapacity;
} Student;

// Global variables
Student *students = NULL; // Dynamic array of students
int studentCount = 0;
int studentCapacity = 0;

// Function to add a student
void addStudent(int id, const char* name) {
    if (studentCount == studentCapacity) {
        // Increase capacity
        studentCapacity = (studentCapacity == 0) ? 1 : studentCapacity * 2;
        students = realloc(students, studentCapacity * sizeof(Student));
        if (students == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    students[studentCount].id = id;
    strncpy(students[studentCount].name, name, NAME_LENGTH - 1);
    students[studentCount].name[NAME_LENGTH - 1] = '\0'; // Ensure null-termination
    students[studentCount].courses = NULL;
    students[studentCount].courseCount = 0;
    students[studentCount].courseCapacity = 0;
    studentCount++;
    printf("Student added successfully.\n");
}

// Function to delete a student
void deleteStudent(int id) {
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
            // Free the memory allocated for the courses of the student
            free(students[i].courses);
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

// Function to search for a student
void searchStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Student found: ID=%d, Name=%s\n", students[i].id, students[i].name);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to display all students
void displayAllStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
    } else {
        for (int i = 0; i < studentCount; i++) {
            printf("ID=%d, Name=%s\n", students[i].id, students[i].name);
            for (int j = 0; j < students[i].courseCount; j++) {
                printf("  Course ID=%d, Course Name=%s\n", students[i].courses[j].courseId, students[i].courses[j].courseName);
            }
        }
    }
}

// Function to add a course to a student
void addCourseToStudent(int studentId, int courseId, const char* courseName) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == studentId) {
            if (students[i].courseCount == students[i].courseCapacity) {
                students[i].courseCapacity = (students[i].courseCapacity == 0) ? 1 : students[i].courseCapacity * 2;
                students[i].courses = realloc(students[i].courses, students[i].courseCapacity * sizeof(Course));
                if (students[i].courses == NULL) {
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(EXIT_FAILURE);
                }
            }
            students[i].courses[students[i].courseCount].courseId = courseId;
            strncpy(students[i].courses[students[i].courseCount].courseName, courseName, COURSE_NAME_LENGTH - 1);
            students[i].courses[students[i].courseCount].courseName[COURSE_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
            students[i].courseCount++;
            printf("Course added successfully to student ID %d.\n", studentId);
            return;
        }
    }
    printf("Student with ID %d not found.\n", studentId);
}

// Sample main function for testing
int main() {
    addStudent(1, "John Doe");
    addStudent(2, "Jane Smith");
    
    addCourseToStudent(1, 101, "Mathematics");
    addCourseToStudent(1, 102, "Physics");
    addCourseToStudent(2, 201, "Chemistry");

    displayAllStudents();
    
    searchStudent(1);
    deleteStudent(1);
    displayAllStudents();
    searchStudent(1);
    
    // Free allocated memory
    for (int i = 0; i < studentCount; i++) {
        free(students[i].courses);
    }
    free(students);

    return 0;
}
