#include "course.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
struct Course *courses = NULL; // Array to store courses (dynamic allocation)
int numCourses = 0; // Current number of courses

// Function to add a new course
void addCourse(const char* code, const char* name) {
    // Allocate memory for a new course
    struct Course *newCourse = (struct Course *)malloc(sizeof(struct Course));
    
    if (newCourse == NULL) {
        printf("Memory allocation failed. Course could not be added.\n");
        return;
    }
    
    // Copy course code and name into the new course structure
    strncpy(newCourse->code, code, sizeof(newCourse->code) - 1);
    newCourse->code[sizeof(newCourse->code) - 1] = '\0'; // Ensure null-terminated
    strncpy(newCourse->name, name, sizeof(newCourse->name) - 1);
    newCourse->name[sizeof(newCourse->name) - 1] = '\0'; // Ensure null-terminated
    
    // Increase the number of courses
    numCourses++;
    
    // Resize the courses array to accommodate the new course
    courses = (struct Course *)realloc(courses, numCourses * sizeof(struct Course));
    
    if (courses == NULL) {
        printf("Memory reallocation failed. Course could not be added.\n");
        free(newCourse); // Free allocated memory for newCourse
        return;
    }
    
    // Add the new course to the array
    courses[numCourses - 1] = *newCourse;
    
    // Free allocated memory for newCourse (no longer needed)
    free(newCourse);
    
    printf("Course with code %s added successfully.\n", code);
}
