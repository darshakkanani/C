#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct AstrotopApp
{
    char name[100];
    char phone[11];
};

int main()
{
    struct AstrotopApp ast;

    // int size;
    // printf("Enter the size of your name: ");
    // scanf("%d", &size);

    printf("Enter your name (Without spaces and with capital letters): ");
    scanf("%s", ast.name);

    printf("Enter your phone number (Without spaces): ");
    scanf("%s", ast.phone);

    int sum_name = 0;
    for (int i = 0; ast.name[i] != '\0'; i++)
    {
        char c = toupper(ast.name[i]);
        switch (c)
        {
        case 'A':
        case 'I':
        case 'J':
        case 'Q':
        case 'X':
            sum_name += 1;
            break;
        case 'B':
        case 'K':
        case 'R':
            sum_name += 2;
            break;
        case 'C':
        case 'G':
        case 'L':
        case 'S':
            sum_name += 3;
            break;
        case 'D':
        case 'M':
        case 'T':
            sum_name += 4;
            break;
        case 'E':
        case 'H':
        case 'N':
            sum_name += 5;
            break;
        case 'U':
        case 'V':
        case 'W':
            sum_name += 6;
            break;
        case 'O':
        case 'Z':
            sum_name += 7;
            break;
        case 'F':
        case 'P':
            sum_name += 8;
            break;
        }
    }

    int sum_name2 = sum_name;

    int sum_phone = 0;
    for (int i = 0; ast.phone[i] != '\0'; i++)
    {
        sum_phone += ast.phone[i] - '0';
    }

    int sum_phone1 = sum_phone;

    int digit1, sum_phone_digits = 0;
    while (sum_phone > 0)
    {
        digit1 = sum_phone % 10;
        sum_phone_digits += digit1;
        sum_phone /= 10;
    }

    int digit2, sum_name_digits = 0;
    while (sum_name2 > 0)
    {
        digit2 = sum_name2 % 10;
        sum_name_digits += digit2;
        sum_name2 /= 10;
    }

    int cnt = 0;
    for ( int i = 0; i < 10; i++)
    {
        if (ast.phone[i] == 51)
        {
            cnt++;
        }

    }
    if (cnt == 2)
    {
        printf("Friend\n");
    }
    else
    {
        printf("Enemy\n");
    }

    if (sum_name_digits == sum_phone_digits)
    {
        printf("Yes, your name and phone number have the same astrological value.\n");
    }
    else
    {
        printf("No, your name and phone number don't have the same astrological value.\n");
    }

    return 0;
}
