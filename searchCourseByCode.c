#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure to store course information
typedef struct Course {
    char courseName[50];
    char courseID[10]; // Changed courseID to string
    struct Course* next;
} Course;

// Function to add course details
Course* addCourse(Course* head, const char* courseName, const char* courseID) {
    // Allocate memory for the new course
    Course* newCourse = (Course*)malloc(sizeof(Course));
    if (newCourse == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    // Set the course details
    strcpy(newCourse->courseName, courseName);
    strcpy(newCourse->courseID, courseID);
    newCourse->next = head; // Insert at the beginning of the list

    return newCourse;
}

// Function to search for a course by its code (ID)
Course* searchCourseByCode(Course* head, const char* courseID) {
    Course* current = head;
    while (current != NULL) {
        if (strcmp(current->courseID, courseID) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Return NULL if course is not found
}

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Course* head = NULL;
    int choice;
    char courseName[50];
    char courseID[10];

    while (1) {
        printf("\n1. Add Course\n");
        printf("2. Search Course by Code\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer(); // Clear input buffer after reading choice

        switch (choice) {
            case 1:
                printf("Enter course name: ");
                fgets(courseName, sizeof(courseName), stdin);
                courseName[strcspn(courseName, "\n")] = '\0'; // Remove newline character
                printf("Enter course ID: ");
                fgets(courseID, sizeof(courseID), stdin);
                courseID[strcspn(courseID, "\n")] = '\0'; // Remove newline character
                head = addCourse(head, courseName, courseID);
                printf("Course added successfully.\n");
                break;

            case 2:
                printf("Enter course ID to search: ");
                fgets(courseID, sizeof(courseID), stdin);
                courseID[strcspn(courseID, "\n")] = '\0'; // Remove newline character
                Course* foundCourse = searchCourseByCode(head, courseID);
                if (foundCourse != NULL) {
                    printf("Course found! \nCourse ID: %s \nCourse Name: %s\n", foundCourse->courseID, foundCourse->courseName);
                } else {
                    printf("Course with ID %s not found.\n", courseID);
                }
                break;

            case 3:
                // Free the allocated memory
                while (head != NULL) {
                    Course* temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Exiting the program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
