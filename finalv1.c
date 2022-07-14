#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#define size 8
#define row 8

void EXIT();
bool check_board(int board[][size]);
void play(int board[][size], int USER);
char menu();
void PrintBoard(int board[][size], int column, int USER, int ColorUser1, int ColorUser2);
void color(int *ColorUser1, int *ColorUser2);
int start(int board[][size], char ch, int ColorUser1, int ColorUser2, int turn);

//*****************************************
int main()
{
    printf("\n\nwelcome to  ''4 IN A ROW''  game. \n"
           "we wish you have a nice time... \n\n");
    int turn = 2;
    int ColorUser1 = -1;
    int ColorUser2 = -1;
    char ch;
    int board[size][size] = {0};
    ch = menu();

    while (1)
    {
        switch (ch)
        {

        case 'H':
        case 'h':
            // system("cls");
            /* printf(" HELP 4 In a Row\n\n"

                    "your goal is to get four of your pieces\n"
                    "to line up in a row before the other player does.\n\n"

                    "You choose a game piece color.\n\n"
                    "You'll have several pieces so you're able to fill in the board\n"
                    "The board is arranged with empty spaces.\n\n"

                    "You and your opponent take turns placing your pieces in those spaces in\n"
                    "an effort to connect four of your own pieces in a row\n\n"
                    "you can EXIT ever you enter the (E) in game.\n");*/
            ch = menu();

            break;

        case 'S':
        case 's':
            color(&ColorUser1, &ColorUser2);
            PrintBoard(board, 0, 0, 0, 0);
            start(board, ch, ColorUser1, ColorUser2, turn);
            break;

        case 'E':
        case 'e':

            EXIT();
            break;

        default:
            system("cls");
            printf("\n\033[31m PLS ENTER VALID WORD!!! \033[0m\n");
            ch = menu();
            break;
        }
    }

    return 0;
}
//*****************************************
bool check_board(int board[][size])
{
    int i;
    int j;

    for (i = 0; i < row; i++) // check kardane satrha
    {
        int num = 0;

        for (j = 0; j < size; j++)
        {
            if (board[i][j] == board[i][j + 1] && board[i][j] != 0)
            {
                num++;
            }

            else
            {
                num = 0;
            }

            if (num == 3)
            {
                return true;
            }
        }
    }

    for (size_t j = 0; j < size; j++) // cheack kardane sotonha
    {
        int num = 0;

        for (size_t i = 0; i < row; i++)
        {
            if (board[i][j] == board[i + 1][j] && board[i][j] != 0)
            {
                num++;
            }

            else
            {
                num = 0;
            }

            if (num == 3)
            {
                return true;
            }
        }
    }

    int first;

    for (size_t i = 3; i <= 7; i++) // cheack kardane ghotrhaye asli
    {
        int num = 0;
        int copy_i = i;
        int copy_j = 0;
        first = board[copy_i][copy_j];

        do
        {
            copy_i--;
            copy_j++;

            if (first != 0 && first == board[copy_i][copy_j])
            {
                num++;
            }
            else
            {
                first = board[copy_i][copy_j];
                num = 0;
            }
            if (num == 3)
            {
                return true;
            }
        } while (copy_i != 0);
    }

    for (size_t j = 1; j <= 4; j++) // cheack kardane ghotrhaye asli
    {
        int num = 0;
        int copy_i = 7;
        int copy_j = j;
        first = board[copy_i][copy_j];

        do
        {
            copy_i--;
            copy_j++;

            if (first != 0 && first == board[copy_i][copy_j])
            {
                num++;
            }
            else
            {
                first = board[copy_i][copy_j];
                num = 0;
            }
            if (num == 3)
            {
                return true;
            }
        } while (copy_j != 7);
    }

    for (size_t i = 0; i <= 4; i++) // cheack kardane ghotrhaye fari
    {
        int num = 0;
        int copy_i = i;
        int copy_j = 0;
        first = board[copy_i][copy_j];

        do
        {
            copy_i++;
            copy_j++;

            if (first != 0 && first == board[copy_i][copy_j])
            {
                num++;
            }
            else
            {
                first = board[copy_i][copy_j];
                num = 0;
            }
            if (num == 3)
            {
                return true;
            }

        } while (copy_i != 7);
    }

    for (size_t j = 1; j <= 4; j++) // cheack kardane ghotrhaye fari
    {
        int num = 0;
        int copy_i = 0;
        int copy_j = j;
        first = board[copy_i][copy_j];

        do
        {
            copy_i++;
            copy_j++;

            if (first != 0 && first == board[copy_i][copy_j])
            {
                num++;
            }
            else
            {
                first = board[copy_i][copy_j];
                num = 0;
            }
            if (num == 3)
            {
                return true;
            }
        } while (copy_j != 7);
    }

    return false;
}
//*****************************************
void play(int board[][size], int USER)
{

    if (check_board(board) && USER == 1)
    {
        printf("\n\n\nWIN USER '1' \n");
        printf("press any key to exit...\n");
        getch();
        EXIT();
    }
    else if (check_board(board) && USER == 2)
    {
        printf("WIN USER '2' \n");
        printf("press any key to exit...\n");
        getch();
        EXIT();
    }
}
//*****************************************
char menu()
{
    printf(
        "choise what do you want to happen?\n"
        "1 . (H)ELP\n"
        "2 . (S)TART\n"
        "3 . (E)XIT\n"
        "Enter choise ---->  ");
    char choise;
    scanf("%c", &choise);
    return choise;
}
//*****************************************
void PrintBoard(int board[][size], int column, int USER, int ColorUser1, int ColorUser2)
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
    printf("   1     2     3     4     5     6     7     8\n");
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
//*****************************************
void color(int *ColorUser1, int *ColorUser2)
{
    do
    {
        *ColorUser1 = -1;

        printf("USER'1' pls choise your color:\n"
               "Red(0)    Yellow(1)    Green(2)    Blue(3)\n"
               "Enter choise ---->  ");
        scanf("%d", ColorUser1);
        if (*ColorUser1 == -1)
        {
            EXIT();
        }
    } while (*ColorUser1 >= 4 && *ColorUser1 <= -1);

    do
    {
        *ColorUser2 = -1;
        printf("\nUSER'2' pls choise your color:\n"
               "you cant choise same color as the user 1\n"
               "Red(0)    Yellow(1)    Green(2)    Blue(3)\n"
               "Enter choise ---->  ");
        scanf("%d", ColorUser2);
        if (*ColorUser2 == -1)
        {
            EXIT();
        }
    } while (*ColorUser2 >= 4 && *ColorUser2 <= -1);

    do
    {
        if (*ColorUser1 == *ColorUser2)
        {
            printf("same color pls change color USER (1) or USER (2)\n"
                   "tell me user number to change color ---> ");
            int change = 0;
            scanf("%d", &change);
            if (change == 1)
            {
                *ColorUser1 = -1;
                printf("user1 pls choise your color:\n"
                       "Red(0)    Yellow(1)    Green(2)    Blue(3)\n"
                       "Enter choise ---->  ");
                scanf("%d", ColorUser1);
                if (*ColorUser1 == -1)
                {
                    EXIT();
                }
            }
            else if (change == 2)
            {
                *ColorUser2 = -1;
                printf("\nuser2 pls choise your color:\n"
                       "you cant choise same color as the user 1\n "
                       "Red(0)    Yellow(1)    Green(2)    Blue(3)\n"
                       "Enter choise ---->  ");
                scanf("%d", ColorUser2);
                if (*ColorUser2 == -1)
                {
                    EXIT();
                }
            }
        }

    } while (*ColorUser1 == *ColorUser2);
}
//*****************************************
int start(int board[][size], char ch, int ColorUser1, int ColorUser2, int turn)
{

    while (1)
    {
        int column1 = 0;
        int column2 = 0;
        if (turn % 2 == 0)
        {
            do
            {
                printf("turn USER'1' choise column (1-8) --->");
                scanf("%d", &column1);
                if (column1 == 0)
                {
                    EXIT();
                }
            } while (column1 >= 9 || column1 <= 0);

            column1--;
            system("cls");
            PrintBoard(board, column1, 1, ColorUser1, ColorUser2);
            play(board, 1);
            turn++;
        }
        else
        {
            do
            {
                printf("turn USER'2' choise column (1-8) --->");
                scanf("%d", &column2);
                if (column2 == 0)
                {
                    EXIT();
                }
            } while (column2 >= 9 || column2 <= 0);

            column2--;
            system("cls");
            PrintBoard(board, column2, 2, ColorUser1, ColorUser2);
            play(board, 2);
            turn++;
        }
    }
}
void EXIT()
{
    system("cls");
    printf("\n until next time, Gby ...\n");
    exit(0);
}
