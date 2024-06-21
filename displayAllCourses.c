// displayAllCourses.c
#include "displayAllCourses.h"

/**
 * Function to display all courses with formatted output for better readability.
 */
void displayAllCourses() {
    printf("+-----------+--------------------------+\n");
    printf("| Course ID | Course Name              |\n");
    printf("+-----------+--------------------------+\n");

    for (int i = 0; i < courseCount; i++) {
        printf("| %9d | %-24s |\n", courses[i].courseID, courses[i].courseName);
    }

    printf("+-----------+--------------------------+\n");
}
