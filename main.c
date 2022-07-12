#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 10
#define row 8
#define column 8
int ColorUser1;
int ColorUser2;

char menu()
{

    printf("\n\nwelcome to  ''4 IN A ROW''  game. \n"
           "we wish you have a nice time... \n\n"
           "choise what do you want to happen?\n"
           "1 . (H)ELP\n"
           "2 . (S)TART\n"
           "3 . (E)XIT\n"
           "Enter choise ---->  ");
    char choise;
    scanf("%c", &choise);
    return choise;
}
void color()
{

    printf("user1 pls choise your color:\n"
           "Red(0)    Yellow(1)    Green(2)    Blue(3)\n"
           "Enter choise ---->  ");
    scanf("%d", &ColorUser1);

    printf("\nuser2 pls choise your color:\n"
           "you cant choise same color as the user 1\n"
           "Red(0)    Yellow(1)    Green(2)    Blue(3)\n"
           "Enter choise ---->  ");
    scanf("%d", &ColorUser2);

    if (ColorUser1 == ColorUser2)
    {
        printf("same color pls change color user (1) or user (2)\n"
               "tell me user number to change color ---> ");
        int change = 0;
        scanf("%d", &change);
        if (change == 1)
        {
            printf("user1 pls choise your color:\n"
                   "Red(0)    Yellow(1)    Green(2)    Blue(3)\n"
                   "Enter choise ---->  ");
            scanf("%d", &ColorUser1);
        }
        else if (change == 2)
        {
            printf("\nuser2 pls choise your color:\n"
                   "you cant choise same color as the user 1\n "
                   "Red(0)    Yellow(1)    Green(2)    Blue(3)\n"
                   "Enter choise ---->  ");
            scanf("%d", &ColorUser2);
        }
    }
}
void chart()
{
    // start
    printf("\033[95m%c\033[0m", 43);
    for (size_t i = 0; i < SIZE * 4 - 1; i++)
        printf("\033[95m%c\033[0m", 45);
    printf("\033[95m%c\033[0m \n", 43); // end start
    for (size_t j = 0; j < 8; j++)
    {

        // start mid
        for (size_t i = 0; i < SIZE - 1; i++)
        {
            printf("\033[95m%c\033[0m", 179);
            printf("    ");
        }
        printf("\n"); // end mid

        // finish
        printf("\033[95m%c\033[0m", 43);
        for (size_t i = 0; i < SIZE * 4 - 1; i++)
            printf("\033[95m%c\033[0m", 45);
        printf("\033[95m%c\033[0m\n", 43); // end finish
    }
}
void start()
{
    color();
    chart();
}
void Square()
{
    // red 0
    for (size_t i = 0; i < 3; i++)
    {

        printf("\033[31m%c\033[0m", 178);
    }
    printf("\n");
    // yellow 1
    for (size_t i = 0; i < 3; i++)
    {

        printf("\033[33m%c\033[0m", 178);
    }
    printf("\n");
    // green 2
    for (size_t i = 0; i < 3; i++)
    {

        printf("\033[32m%c\033[0m", 178);
    }
    printf("\n");
    // blu 3
    for (size_t i = 0; i < 3; i++)
    {

        printf("\033[34m%c\033[0m", 178);
    }
    printf("\n");
}

int main()
{
    char ch;
    ch = menu();

    switch (ch)
    {
    case 'H':
        /* code */
        break;
    case 'S':
        start();
        break;
    case 'E':
        /* code */
        break;

    default:
        printf("unknown word!!!\n");
        break;
    }

    return 0;
}
