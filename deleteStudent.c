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

// Function to initialize the StudentList
void initStudentList(StudentList* list, int capacity) {
    list->students = (Student*)malloc(capacity * sizeof(Student)); // Allocate memory for students
    list->count = 0;                                               // Initialize student count to 0
    list->capacity = capacity;                                     // Set the initial capacity
}

// Function to add a student to the list
void addStudent(StudentList* list, int id, const char* name, int age) {
    // Check if we need to resize the array
    if (list->count == list->capacity) {
        list->capacity *= 2;
        list->students = (Student*)realloc(list->students, list->capacity * sizeof(Student)); // Reallocate memory
    }

    // Add the new student's details to the array
    list->students[list->count].id = id;
    strcpy(list->students[list->count].name, name); // Copy the name to the student's name field
    list->students[list->count].age = age;
    list->count++; // Increment the count of students
}

// Function to delete a student by ID
void deleteStudent(StudentList* list, int id) {
    int found = 0;
    for (int i = 0; i < list->count; i++) {
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
            list->students = (Student*)realloc(list->students, list->count * sizeof(Student));
        } else {
            free(list->students);
            list->students = NULL;
        }
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}

int main() {
    StudentList list; // Declare a StudentList
    initStudentList(&list, 2); // Initialize the list with a capacity of 2

    // Add three students to the list
    addStudent(&list, 1, "Alice", 20);
    addStudent(&list, 2, "Bob", 21);
    addStudent(&list, 3, "Charlie", 22);

    // Print the details of all students in the list
    for (int i = 0; i < list.count; i++) {
        printf("Student %d: %s, %d years old\n", list.students[i].id, list.students[i].name, list.students[i].age);
    }

    // Delete a student by ID
    deleteStudent(&list, 2);

    // Print the details of all students in the list after deletion
    printf("\nAfter deletion:\n");
    for (int i = 0; i < list.count; i++) {
        printf("Student %d: %s, %d years old\n", list.students[i].id, list.students[i].name, list.students[i].age);
    }

    // Free the allocated memory for the students array
    free(list.students);

    return 0; // Return 0 to indicate successful execution
}