#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define size 8
void PrintBoard(int board[][size])
{
    // start
    printf("\033[95m%c\033[0m", 43);
    for (size_t i = 0; i < size * 5 + 7; i++)
        printf("\033[95m%c\033[0m", 45);
    printf("\033[95m%c\033[0m \n", 43); // end start

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            printf("\033[95m%c\033[0m", 179);
            if (board[i][j] == 0)
            {
                printf("     ");
            }
        }
        printf("\033[95m%c\033[0m", 179);
        printf("\n");

        printf("\033[95m%c\033[0m", 43);
        for (size_t i = 0; i < size * 5 + 7; i++)
            printf("\033[95m%c\033[0m", 45);
        printf("\033[95m%c\033[0m \n", 43);
    }
}
void PrintBoard2(int board[][size], int column, int USER, int ColorUser1, int ColorUser2)
{

    if (USER == 1)
    {
        for (int i = 7; i >= 0; i--)
        {
            if (board[i][column] == 0)
            {
                board[i][column] = 178;
                break;
            }
        }
    }
    if (USER == 2)
    {
        for (int i = 7; i >= 0; i--)
        {
            if (board[i][column] == 0)
            {
                board[i][column] = 177;
                break;
            }
        }
    }

    // start
    printf("\033[95m%c\033[0m", 43);
    for (size_t i = 0; i < size * 5 + 7; i++)
        printf("\033[95m%c\033[0m", 45);
    printf("\033[95m%c\033[0m \n", 43); // end start
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

                switch (ColorUser1)
                {
                case 0:
                    if (board[i][j] != 177)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[31m%c\033[0m", board[i][j]);
                        }
                        printf(" ");
                    }

                    break;
                case 1:
                    if (board[i][j] != 177)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[33m%c\033[0m", board[i][j]);
                        }
                        printf(" ");
                    }

                    break;
                case 2:
                    if (board[i][j] != 177)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[32m%c\033[0m", board[i][j]);
                        }
                        printf(" ");
                    }

                    break;
                case 3:
                    if (board[i][j] != 177)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[34m%c\033[0m", board[i][j]);
                        }
                        printf(" ");
                    }

                    break;
                }

                switch (ColorUser2)
                {
                case 0:
                    if (board[i][j] != 178)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[31m%c\033[0m", board[i][j]);
                        }
                        printf(" ");
                    }
                   
                    break;
                case 1:
                    if (board[i][j] != 178)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[33m%c\033[0m", board[i][j]);
                        }
                        printf(" ");
                    }
                    
                    break;
                case 2:
                    if (board[i][j] != 178)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[32m%c\033[0m", board[i][j]);
                        }
                        printf(" ");
                    }
                   
                    break;
                case 3:
                    if (board[i][j] != 178)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[34m%c\033[0m", board[i][j]);
                        }
                        printf(" ");
                    }
                    

                    break;
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
}
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
    int column1 = 0;
    int column2 = 0;
    int turn = 2;
    color(&ColorUser1, &ColorUser2);
    printf("\n%d\n%d\n", ColorUser1, ColorUser2);
    PrintBoard(board);

    while (ch != 'E')
    {
        if (turn % 2 == 0)
        {
            printf("turn user1 choise column --->");
            scanf("%d", &column1);
            PrintBoard2(board, column1, 1, ColorUser1, ColorUser2);
            turn++;
        }
        else
        {
            printf("turn user2 choise column --->");
            scanf("%d", &column2);
            PrintBoard2(board, column2, 2, ColorUser1, ColorUser2);
            turn++;
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
