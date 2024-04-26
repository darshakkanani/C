#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student
{
    int roll_no;
    char name[50];
    char gender;
    int marks[5];
    float percentage;
};

float calculatePercentage(int marks[], int totalSubjects)
{
    float totalMarks = 0;
    for (int i = 0; i < totalSubjects; i++)
    {
        totalMarks += marks[i];
    }
    return totalMarks / totalSubjects;
}

void displayStudentList(struct Student students[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].percentage < students[j + 1].percentage)
            {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("Student List Sorted by Percentage:\n");
    printf("Roll No\tName\tGender\tPercentage\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t%c\t%.2f%%\n", students[i].roll_no, students[i].name, students[i].gender, students[i].percentage);
    }
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n > MAX_STUDENTS)
    {
        printf("Maximum number of students exceeded. Please try again with fewer students.\n");
        return 1;
    }

    struct Student students[MAX_STUDENTS];

    for (int i = 0; i < n; i++)
    {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Gender (M/F): ");
        scanf(" %c", &students[i].gender);
        printf("Marks in 5 subjects: ");
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &students[i].marks[j]);
        }
        students[i].percentage = calculatePercentage(students[i].marks, 5);
    }

    displayStudentList(students, n);

    return 0;
}
