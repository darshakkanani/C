#include <stdio.h>
#include<string.h>
struct student
{
    char name[50];
    int marks1;
    int marks2;
    int marks3;
};

struct student s[6];

int maxIndex(float arr[], int size)
{
    int max = arr[0];
    int mi = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            mi = i;
        }
    }

    return mi;
}

int main()
{
    for (int i = 0; i < 6; i++)
    {
        printf("Enter the name: ");
        scanf("%s", s[i].name);
        printf("CTSD marks: ");
        scanf("%d", &s[i].marks1);
        printf("Maths marks: ");
        scanf("%d", &s[i].marks2);
        printf("EEE marks: ");
        scanf("%d", &s[i].marks3);
    }

    float avg[6];
    for (int i = 0; i < 6; i++)
    {
        avg[i] = (s[i].marks1 + s[i].marks2 + s[i].marks3) / 3.0;
    }

    int mi = maxIndex(avg, 6);

    printf("Student: %s\n", s[mi].name);

    return 0;
}
