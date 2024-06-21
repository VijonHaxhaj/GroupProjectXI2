#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
typedef struct Student {
    int id;
    char name[100];
    int age;
} Student;
// Define the structure for a list of students
typedef struct StudentList {
    Student* students;
    int count;
    int capacity;
} StudentList;
// Function to display all student details
void displayAllStudents(const StudentList* list) {
    printf("Student List:\n");
    printf("ID\tName\t\tAge\n");
    printf("-----------------------------\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d\t%-15s\t%d\n", list->students[i].id, list->students[i].name, list->students[i].age);
    }
}
