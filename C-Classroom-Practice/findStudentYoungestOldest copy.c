#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[50];
    int year;
    int month;
    int day;
};

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student s[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", s[i].name);
        printf("Enter birth year of student %d: ", i + 1);
        scanf("%d", &s[i].year);
        printf("Enter birth month of student %d: ", i + 1);
        scanf("%d", &s[i].month);
        printf("Enter birth day of student %d: ", i + 1);
        scanf("%d", &s[i].day);
    }

    int y = 0;
    int o = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i].year > s[o].year ||(s[i].year == s[o].year &&s[i].month > s[o].month) ||(s[i].year == s[o].year &&s[i].month == s[o].month &&s[i].day > s[o].day))
        {
            o = i;
        }

        if (s[i].year < s[y].year ||(s[i].year == s[y].year &&s[i].month < s[y].month) ||(s[i].year == s[y].year &&s[i].month == s[y].month &&s[i].day < s[y].day))
        {
            y = i;
        }
    }

    printf("\nYoungest student:\n");
    printf("Name: %s\n", s[y].name);
    printf("Birth Date: %d/%d/%d\n", s[y].year, s[y].month, s[y].day);

    printf("\nOldest student:\n");
    printf("Name: %s\n", s[o].name);
    printf("Birth Date: %d/%d/%d\n", s[o].year, s[o].month, s[o].day);

    return 0;
}
