#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define SUBJECTS 5

// Structure to represent a student
struct Student {
    int roll_no;
    char name[50];
    char gender;
    int marks[SUBJECTS];
    float percentage;
};

// Function to calculate percentage for a student
void calculatePercentage(struct Student *student) {
    int totalMarks = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        totalMarks += student->marks[i];
    }
    student->percentage = (float)totalMarks / SUBJECTS;
}

int main() {
    struct Student students[MAX_STUDENTS];
    int num_students;

    // Input number of students
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Input details for each student
    for (int i = 0; i < num_students; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Gender (M/F): ");
        scanf(" %c", &students[i].gender);
        printf("Marks in 5 subjects: ");
        for (int j = 0; j < SUBJECTS; j++) {
            scanf("%d", &students[i].marks[j]);
        }
        // Calculate percentage for each student
        calculatePercentage(&students[i]);
    }

    // Display details and percentage for each student
    printf("\nStudent Records:\n");
    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Name: %s\n", students[i].name);
        printf("Gender: %c\n", students[i].gender);
        printf("Marks: ");
        for (int j = 0; j < SUBJECTS; j++) {
            printf("%d ", students[i].marks[j]);
        }
        printf("\nPercentage: %.2f%%\n", students[i].percentage);
    }

    return 0;
}
