#include "deleteCourse.h"

// Global variables
Course* courses = NULL;
int courseCount = 0;

/**
 * Function to delete a course by its ID.
 *
 * @param id The ID of the course to delete.
 */
void delete_course(int id) {
    int index = -1;

    // Task for Team Member 1: Implement the basic course deletion logic
    // Find the index of the course to be deleted
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].courseID == id) {
            index = i;
            break;
        }
    }

    // If the course is not found, print an error message and return
    if (index == -1) {
        printf("Course with ID %d not found.\n", id);
        return;
    }

    // Task for Team Member 2: Implement the array shift logic
    // Shift the courses to fill the gap left by the deleted course
    for (int i = index; i < courseCount - 1; i++) {
        courses[i] = courses[i + 1];
    }

    // Task for Team Member 3: Handle memory reallocation
    // Decrease the course count
    courseCount--;

    // Reallocate memory to resize the courses array
    courses = realloc(courses, courseCount * sizeof(Course));

    // Check if memory reallocation was successful
    if (courseCount > 0 && courses == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(1);
    }

    printf("Course with ID %d deleted successfully.\n", id);
}
