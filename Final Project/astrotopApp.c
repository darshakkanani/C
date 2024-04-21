// #include <stdio.h>

// struct astrotopApp
// {
//     int num;
//     char name[100];
// } ast;

// int main()
// {
//     int size;
//     printf("Enter the size of your name: ");
//     scanf("%d", &size);

//     printf("Enter the size of your name(Without space and With capital latters): ");

//     char name[100];
//     for (int i = 0; i < size; i++)
//     {
//         scanf("%s", &name[i]);
//     }

//     int num;
//     printf("Enter your phone number(Without space): ");
//     scanf("%d", &num);

//     char number[11];
//     int num1;
//     scanf("%10s", number);

//     int sum = 0;
//     for (int i = 0; i < size; i++)
//     {
//         int count = 0;
//         if (name[i] == 'A' || name[i] == 'I' || name[i] == 'J' || name[i] == 'Q' || name[i] == 'X')
//         {
//             count = 1;
//         }
//         else if (name[i] == 'B' || name[i] == 'K' || name[i] == 'R')
//         {
//             count = 2;
//         }
//         else if (name[i] == 'C' || name[i] == 'G' || name[i] == 'L' || name[i] == 'S')
//         {
//             count = 3;
//         }
//         else if (name[i] == 'D' || name[i] == 'M' || name[i] == 'T')
//         {
//             count = 4;
//         }
//         else if (name[i] == 'E' || name[i] == 'H' || name[i] == 'N' || name[i] == 'X')
//         {
//             count = 5;
//         }
//         else if (name[i] == 'U' || name[i] == 'V' || name[i] == 'W')
//         {
//             count = 6;
//         }
//         else if (name[i] == 'O' || name[i] == 'Z')
//         {
//             count = 7;
//         }
//         else if (name[i] == 'F' || name[i] == 'P')
//         {
//             count = 8;
//         }
//         sum = sum + count;
//     }

//     int number1, digit1, sum1 = 0;
//     while (sum > 0)
//     {
//         digit1 = number1 % 10;
//         sum1 += digit1;
//         number1 /= 10;
//     }

//     int sum2 = 0;
//     for (int i = 0; i < 10; i++)
//     {
//         sum2 = number[i] + sum2;
//     }

//     int number2, digit2, sum3 = 0;
//     while (sum2 > 0)
//     {
//         digit2 = number2 % 10;
//         sum3 += digit2;
//         number2 /= 10;
//     }

//     if (sum1 == sum3)
//     {
//         printf("Yes");
//     }
//     else
//     {
//         printf("No");
//     }
// }