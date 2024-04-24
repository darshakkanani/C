#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to represent a student
struct Student {
    int roll_no;
    char name[50];
    char gender;
    int marks[5];
    float percentage;
};

// Function to calculate percentage for a student
float calculatePercentage(int marks[], int totalSubjects) {
    int totalMarks = 0;
    for (int i = 0; i < totalSubjects; i++) {
        totalMarks += marks[i];
    }
    return (float)totalMarks / totalSubjects;
}

// Function to display student list sorted by percentage
void displayStudentList(struct Student students[], int n) {
    // Sort the students based on percentage (bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].percentage < students[j + 1].percentage) {
                // Swap students
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // Display student list
    printf("Student List Sorted by Percentage:\n");
    printf("Roll No\tName\tGender\tPercentage\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%c\t%.2f%%\n", students[i].roll_no, students[i].name, students[i].gender, students[i].percentage);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n > MAX_STUDENTS) {
        printf("Maximum number of students exceeded. Please try again with fewer students.\n");
        return 1;
    }

    struct Student students[MAX_STUDENTS];

    // Input student details
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Gender (M/F): ");
        scanf(" %c", &students[i].gender);
        printf("Marks in 5 subjects: ");
        for (int j = 0; j < 5; j++) {
            scanf("%d", &students[i].marks[j]);
        }
        // Calculate percentage
        students[i].percentage = calculatePercentage(students[i].marks, 5);
    }

    // Display student list sorted by percentage
    displayStudentList(students, n);

    return 0;
}
