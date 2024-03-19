#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[50];
    int birth_year;
    int birth_month;
    int birth_day;
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
        scanf("%d", &s[i].birth_year);
        printf("Enter birth month of student %d: ", i + 1);
        scanf("%d", &s[i].birth_month);
        printf("Enter birth day of student %d: ", i + 1);
        scanf("%d", &s[i].birth_day);
    }

    int youngest_index = 0;
    int oldest_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i].birth_year > s[oldest_index].birth_year ||
            (s[i].birth_year == s[oldest_index].birth_year &&
             s[i].birth_month > s[oldest_index].birth_month) ||
            (s[i].birth_year == s[oldest_index].birth_year &&
             s[i].birth_month == s[oldest_index].birth_month &&
             s[i].birth_day > s[oldest_index].birth_day))
        {
            oldest_index = i;
        }

        if (s[i].birth_year < s[youngest_index].birth_year ||
            (s[i].birth_year == s[youngest_index].birth_year &&
             s[i].birth_month < s[youngest_index].birth_month) ||
            (s[i].birth_year == s[youngest_index].birth_year &&
             s[i].birth_month == s[youngest_index].birth_month &&
             s[i].birth_day < s[youngest_index].birth_day))
        {
            youngest_index = i;
        }
    }

    printf("\nYoungest student:\n");
    printf("Name: %s\n", s[youngest_index].name);
    printf("Birth Date: %d/%d/%d\n", s[youngest_index].birth_year,
           s[youngest_index].birth_month,
           s[youngest_index].birth_day);

    printf("\nOldest student:\n");
    printf("Name: %s\n", s[oldest_index].name);
    printf("Birth Date: %d/%d/%d\n", s[oldest_index].birth_year,
           s[oldest_index].birth_month,
           s[oldest_index].birth_day);

    return 0;
}
