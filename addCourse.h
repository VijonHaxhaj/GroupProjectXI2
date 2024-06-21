#ifndef COURSE_H_
#define COURSE_H_

// Define a structure to store course information
struct Course {
    char code[20];
    char name[50];
    // Add more fields as needed (e.g., instructor, credits, etc.)
};

// Function prototypes
void addCourse(const char* code, const char* name);

#endif /* COURSE_H_ */
