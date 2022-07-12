#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define size 8
void color(int *ColorUser1, int *ColorUser2)
{

    printf("user1 pls choise your color:\n"
           "Red(0)    Yellow(1)    Green(2)    Blue(3)\n"
           "Enter choise ---->  ");
    scanf("%d", ColorUser1);

    printf("\nuser2 pls choise your color:\n"
           "you cant choise same color as the user 1\n"
           "Red(0)    Yellow(1)    Green(2)    Blue(3)\n"
           "Enter choise ---->  ");
    scanf("%d", ColorUser2);

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
int start(int board[][size], char ch)
{
    int ColorUser1;
    int ColorUser2;
    color(&ColorUser1, &ColorUser2);
    printf("\n%d\n%d\n",ColorUser1,ColorUser2);

    while (ch != 'E')
    {

        // start
        printf("\033[95m%c\033[0m", 43);
        for (size_t i = 0; i < size * 5 + 7; i++)
            printf("\033[95m%c\033[0m", 45);
        printf("\033[95m%c\033[0m \n", 43); // end start
        int check = 1;
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                printf("\033[95m%c\033[0m", 179);
                if (board[i][j] == 0)
                {
                    printf("     ");
                }
                else
                {

                    if (check == 1)
                    {
                        if (ColorUser1 == 0)
                        {
                            printf(" ");
                            for (size_t k = 0; k < 3; k++)
                            {
                                printf("\033[31m%c\033[0m", board[i][j]);
                            }
                            printf(" ");
                        }
                        if (ColorUser1 == 1)
                        {
                            printf(" ");
                            for (size_t k = 0; k < 3; k++)
                            {
                                printf("\033[33m%c\033[0m", board[i][j]);
                            }
                            printf(" ");
                        }
                        if (ColorUser1 == 2)
                        {
                            printf(" ");
                            for (size_t k = 0; k < 3; k++)
                            {
                                printf("\033[32m%c\033[0m", board[i][j]);
                            }
                            printf(" ");
                        }
                        if (ColorUser1 == 3)
                        {
                            printf(" ");
                            for (size_t k = 0; k < 3; k++)
                            {
                                printf("\033[34m%c\033[0m", board[i][j]);
                            }
                            printf(" ");
                        }
                        check = 2;
                    }
                    else
                    {
                        if (ColorUser2 == 0)
                        {
                            printf(" ");
                            for (size_t k = 0; k < 3; k++)
                            {
                                printf("\033[31m%c\033[0m", board[i][j]);
                            }
                            printf(" ");
                        }
                        if (ColorUser2 == 1)
                        {
                            printf(" ");
                            for (size_t k = 0; k < 3; k++)
                            {
                                printf("\033[33m%c\033[0m", board[i][j]);
                            }
                            printf(" ");
                        }
                        if (ColorUser2 == 2)
                        {
                            printf(" ");
                            for (size_t k = 0; k < 3; k++)
                            {
                                printf("\033[32m%c\033[0m", board[i][j]);
                            }
                            printf(" ");
                        }
                        if (ColorUser2 == 3)
                        {
                            printf(" ");
                            for (size_t k = 0; k < 3; k++)
                            {
                                printf("\033[34m%c\033[0m", board[i][j]);
                            }
                            printf(" ");
                        }
                        check = 1;
                    }
                }
            }
            printf("\033[95m%c\033[0m", 179);
            printf("\n");

            printf("\033[95m%c\033[0m", 43);
            for (size_t i = 0; i < size * 5 + 7; i++)
                printf("\033[95m%c\033[0m", 45);
            printf("\033[95m%c\033[0m \n", 43);
        }

        int column = -1;
        if (check == 1)
        {
            printf("\n turn user1 enter number of column\n");
        }
        else if (check == 2)
        {
            printf("\n turn user2 enter number of column\n");
        }

        scanf("%d", &column);
        for (size_t i = 7; i >= 0; i--)
        {
            if (board[i][column] == 0)
            {
                board[i][column] = 178;
                break;
            }
        }
    }
}
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

int main()
{

    char ch;
    int board[size][size];

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }

    ch = menu();
    switch (ch)
    {
    case 'H':
        /* code */
        break;
    case 'S':
        start(board, ch);
        break;
    case 'E':
        /* code */
        break;

    default:
        printf("unknown word!!!\n");
        break;
    }

    // system("cls");
    return 0;
}
