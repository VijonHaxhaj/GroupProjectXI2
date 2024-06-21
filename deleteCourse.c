#include "deleteCourse.h"

//these are Global variables that can be used inside functions and in the main function
Course* courses = NULL;
int courseCount = 0;

/*
@param id The ID of the course to delete.
 */
void delete_course(int id) {
    int index = -1;

   
    //This is going to find the index of the course to be deleted
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

   // Shift the courses to fill the gap left by the deleted course
for (int i = index; i < courseCount - 1; i++) {
    courses[i] = courses[i + 1];  // Each course is moved one position left in the array.
}

    }
//this is going to decrease the course count
    courseCount--;

    //this will reallocate memory to resize the courses array only if there are remaining courses
    if (courseCount > 0) {
        Course* temp = realloc(courses, courseCount * sizeof(Course));

        //this is going to check if memory reallocation was successful
        if (temp == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(1);
        }

        courses = temp;
    } else {
        // if there are no remaining courses, free the allocated memory and set courses to NULL
        free(courses);
        courses = NULL;
    }
}
    
    }
// this will print "deleted successfully"
    printf("Course with ID %d deleted successfully.\n", id);
}
