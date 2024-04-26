#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define SUBJECTS 5

struct Student
{
    int roll_no;
    char name[50];
    char gender;
    int marks[SUBJECTS];
    float percentage;
};

void calculatePercentage(struct Student *student)
{
    float totalMarks = 0;
    for (int i = 0; i < SUBJECTS; i++)
    {
        totalMarks += student->marks[i];
    }
    student->percentage = totalMarks / SUBJECTS;
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int num_students;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Gender (M/F): ");
        scanf(" %c", &students[i].gender);
        printf("Marks in 5 subjects: ");
        for (int j = 0; j < SUBJECTS; j++)
        {
            scanf("%d", &students[i].marks[j]);
        }
        calculatePercentage(&students[i]);
    }

    printf("\nStudent Records:\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Name: %s\n", students[i].name);
        printf("Gender: %c\n", students[i].gender);
        printf("Marks: ");
        for (int j = 0; j < SUBJECTS; j++)
        {
            printf("%d ", students[i].marks[j]);
        }
        printf("\nPercentage: %.2f%%\n", students[i].percentage);
    }

    return 0;
}
