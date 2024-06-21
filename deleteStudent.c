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
// Function to delete student details
void deleteStudent(StudentList* list, int id) {
    int found = 0;
    for (int i = 0; i < list->count; i++)
{
        if (list->students[i].id == id) {
            found = 1;
            // Shift the remaining students
            for (int j = i; j < list->count - 1; j++) {
                list->students[j] = list->students[j + 1];
            }
list->count--;
            break;
        }
    }

    if (found) {
        // Reallocate memory to shrink the array if necessary
        if (list->count > 0) {
            list->students = (Student)realloc(list->students, list->count sizeof(Student));
} else {
            free(list->students);
            list->students = NULL;
        }
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}
