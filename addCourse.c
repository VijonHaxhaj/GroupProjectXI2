#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure to store course information
typedef struct Course {
    char courseName[50];
    int courseID;
    struct Course* next;
} Course;

// Function to add course details
Course* addCourse(Course* head, const char* courseName, int courseID) {
    // Allocate memory for the new course
    Course* newCourse = (Course*)malloc(sizeof(Course));
    if (newCourse == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    // Set the course details
    strcpy(newCourse->courseName, courseName);
    newCourse->courseID = courseID;
    newCourse->next = head; // Insert at the beginning of the list

    return newCourse;
}

int main() {
    Course* head = NULL;

    // Adding courses
    head = addCourse(head, "Mathematics", 101);
    head = addCourse(head, "Physics", 102);
    head = addCourse(head, "Chemistry", 103);

    // Print the list of courses
    Course* temp = head;
    while (temp != NULL) {
        printf("Course ID: %d, Course Name: %s\n", temp->courseID, temp->courseName);
        temp = temp->next;
    }

    // Free the allocated memory
    while (head != NULL) {
        Course* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
