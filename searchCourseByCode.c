#include <stdio.h>
#include <string.h>

#define MAX_COURSES 100
#define CODE_LENGTH 10
#define NAME_LENGTH 50

typedef struct {
    char code[CODE_LENGTH];
    char name[NAME_LENGTH];
    int credits;
} Course;

Course courses[MAX_COURSES];
int courseCount = 0;

void searchCourseByCode(char *code) {
    int found = 0;
    for (int i = 0; i < courseCount; i++) {
        if (strcmp(courses[i].code, code) == 0) {
            printf("Course found:\n");
            printf("Code: %s\n", courses[i].code);
            printf("Name: %s\n", courses[i].name);
            printf("Credits: %d\n", courses[i].credits);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Course with code %s not found.\n", code);
    }
}

void searchCourseByName(char *name) {
    int found = 0;
    for (int i = 0; i < courseCount; i++) {
        if (strcmp(courses[i].name, name) == 0) {
            printf("Course found:\n");
            printf("Code: %s\n", courses[i].code);
            printf("Name: %s\n", courses[i].name);
            printf("Credits: %d\n", courses[i].credits);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Course with name %s not found.\n", name);
    }
}

int main() {
    // Example courses
    strcpy(courses[0].code, "CS101");
    strcpy(courses[0].name, "Introduction to Computer Science");
    courses[0].credits = 3;
    courseCount++;

    strcpy(courses[1].code, "MATH101");
    strcpy(courses[1].name, "Calculus I");
    courses[1].credits = 4;
    courseCount++;

    // Search for a course by code
    char codeToSearch[CODE_LENGTH];
    printf("Enter course code to search: ");
    scanf("%s", codeToSearch);
    searchCourseByCode(codeToSearch);

    // Search for a course by name
    char nameToSearch[NAME_LENGTH];
    printf("Enter course name to search: ");
    scanf("%s", nameToSearch);
    searchCourseByName(nameToSearch);

    return 0;
}
