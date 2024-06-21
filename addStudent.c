#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
typedef struct Student {
    int id;
    char name[100];
    int age;
} Student;
typedef struct StudentList {
    Student* students;
    int count;
    int capacity;
} StudentList;

void initStudentList(StudentList* list, int capacity) {
    list->students = (Student)malloc(capacity sizeof(Student));
    list->count = 0;
    list->capacity = capacity;
void addStudent(StudentList* list, int id, const char* name, int age) {
    // Check if we need to resize the array
    if (list->count == list->capacity) {
        list->capacity = 2;
        list->students = (Student)realloc(list->students, list->capacity * sizeof(Student));
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

    // Free the allocated memory for the students array
    free(list.students);

    return 0; // Return 0 to indicate successful execution
}
