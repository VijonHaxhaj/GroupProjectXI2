#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

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
    studentCount++;
    printf("Student added successfully.\n");
}

// Function to delete a student
void deleteStudent(int id) {
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
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
        }
    }
}

// Sample main function for testing
int main() {
    addStudent(1, "John Doe");
    addStudent(2, "Jane Smith");
    displayAllStudents();
    searchStudent(1);
    deleteStudent(1);
    displayAllStudents();
    searchStudent(1);
    return 0;
}