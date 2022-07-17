#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <math.h>
//****************************************
#define size 8
#define row 8
//****************************************
FILE *fptr;
FILE *mptr;
//****************************************
int ReConvertB_step(int bin[]);
void merge(int bin[], int step);
void ConvertB_info(int dec, int bin[3]);
void ConvertB_step(int dec, int bin[7]);
void FRead();
void FWrite(int user, int column, int color);
void menu(char *choise);
bool check_board(int board[][size]);
void PrintBoard(int board[][size], int column, int USER, int ColorUser1, int ColorUser2);
void EXIT();
int ChoiseColumn(int turn, int *column);
void Color(int *ColorUser1, int *ColorUser2);
int Start();
//****************************************
struct Info
{
    int USER[3];
    int COLUMN[3];
    int COLOR[3];
};
struct Template
{
    int STEP[7];
};

//****************************************
int main()
{
    char choise;
    menu(&choise);

    while (1)
    {
        switch (choise)
        {
        case 's':
        case 'S':
            Start();
            break;
        case 'f':
        case 'F':
            FRead();
            getch();
            break;
        default:
            printf("\n\033[31m PLS ENTER VALID WORD!!! \033[0m\n");
            break;
        }
        menu(&choise);
        system("cls");
    }

    return 0;
}
//****************************************
void menu(char *choise)
{
    printf(
        "choise what do you want to happen?\n"
        "1 . (H)ELP\n"
        "2 . (S)TART\n"
        "3 . (F)ile\n"
        "4 . (E)XIT\n"
        "Enter choise ---->  ");
    scanf("%c", choise);
}
//****************************************
int Start()
{
    int board[size][size] = {0};
    int turn = 2;
    int step = 1;
    int coloruser1 = -1;
    int coloruser2 = -1;
    int column = -1;
    int bin[7];
    Color(&coloruser1, &coloruser2);
    PrintBoard(board, 0, 0, 0, 0);

    while (step != 65)
    {

        if (turn % 2 == 0)
        {
            ChoiseColumn(turn, &column);
            if (column == -1)
            {
                EXIT();
            }
            system("cls");
            PrintBoard(board, column, 1, coloruser1, coloruser2);
            FWrite(1, column, coloruser1);
            if (check_board(board))
            {
                ConvertB_step(step, bin);
                // printf(" ---------%d\n\n",step);
                // for (size_t i = 0; i < 7; i++)
                // {
                //    printf("%d", bin[i]);
                //}
                // printf("\n");
                // getch();
                merge(bin, step);
                printf("\n\n\nWIN USER '1' \n");
                printf("press any key to exit...\n");
                getch();
                EXIT();
            }
        }
        else
        {
            ChoiseColumn(turn, &column);
            if (column == -1)
            {
                EXIT();
            }
            system("cls");
            PrintBoard(board, column, 2, coloruser1, coloruser2);
            FWrite(2, column, coloruser2);
            if (check_board(board))
            {

                printf("\n\n\nWIN USER '2' \n");
                printf("press any key to exit...\n");
                getch();
                EXIT();
            }
        }
        turn++;
        step++;
    }
}
//****************************************
int ChoiseColumn(int turn, int *column)
{
    do
    {
        printf("turn USER'%d' choise column (0-7) --->", turn % 2 + 1);
        scanf("%d", column);

    } while (*column > 7 || *column < 0);
}
//****************************************
void Color(int *ColorUser1, int *ColorUser2)
{
    // choise color for User 1
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
    // choise color for User 2
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
    // check color 1 vs color 2 to not be same
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
//****************************************
void EXIT()
{
    system("cls");
    printf("\n until next time, Gby ...\n");
    exit(0);
}
//****************************************
void FWrite(int user, int column, int color)
{
    struct Info temp;
    int User[3];
    int Column[3];
    int Color[3];

    ConvertB_info(user, User);
    ConvertB_info(column, Column);
    ConvertB_info(color, Color);

    for (int i = 0; i < 3; i++)
    {
        temp.USER[i] = User[i];
        temp.COLUMN[i] = Column[i];
        temp.COLOR[i] = Color[i];
    }
    // open File
    fptr = fopen("2.bin", "ab+");
    if (fptr == NULL)
    {
        printf("cant open the file\n");
    }

    fwrite(&temp, sizeof(struct Info), 1, fptr);
    fclose(fptr);
    // close File
}
//*****************************************
void FRead()
{
    int bin[7];
    int Step = 0;
    struct Info temp;
    struct Template template;

    mptr = fopen("3.bin", "rb");
    // take the amount of binary
    fread(&template, sizeof(struct Template), 1, mptr);
    for (int i = 0; i < 7; i++)
    {
        printf("%-d", template.STEP[i]);
    }
    printf("\n");
    // take the amount of decimal step for (int i = 0; i < 7; i++)
    for (int i = 0; i < 7; i++)
    {
        bin[i] = template.STEP[i];
    }
    Step = ReConvertB_step(bin);
    //printf("\n\n---------%d------------\n\n",S);

    while (Step != 0)
    {
        fread(&temp, sizeof(struct Info), 1, mptr);
        for (int i = 0; i < 3; i++)
        {
            printf("%-d", temp.USER[i]);
        }
        for (int i = 0; i < 3; i++)
        {
            printf("%-d", temp.COLUMN[i]);
        }
        for (int i = 0; i < 3; i++)
        {
            printf("%-d", temp.COLOR[i]);
        }

        printf("\n");
        Step--;
    }

    fclose(mptr);
}
//*****************************************
void ConvertB_info(int dec, int bin[3]) // get decimal convert to binery
{

    for (int i = 2; i >= 0; --i)
    {
        if (dec % 2 == 1)
        {
            bin[i] = 1;
        }
        else
        {
            bin[i] = 0;
        }

        dec /= 2;
    }
}
//*****************************************
void ConvertB_step(int dec, int bin[7])
{
    for (int i = 6; i >= 0; --i)
    {
        if (dec % 2 == 1)
        {
            bin[i] = 1;
        }
        else
        {
            bin[i] = 0;
        }

        dec /= 2;
    }
}
//*****************************************
int ReConvertB_step(int bin[7])
{
    
        int dec = 0;
        int j = 6;
        for (int i = 0 ; i <7; i++)
        {
            if (bin[i] != 0)
            {
                dec += pow(2, j);
            }
            //printf("\ndec  %d\n",dec);
            j--;
        }

        return dec;
    
}
//*****************************************
void merge(int bin[7], int step)
{
    struct Template template;
    struct Info temp;

    fptr = fopen("2.bin", "rb");
    mptr = fopen("3.bin", "ab+");
    if (mptr == NULL)
    {
        printf("cant open file");
    }

    for (int i = 0; i < 7; i++)
    {
        template.STEP[i] = bin[i];
    }

    fwrite(&template, sizeof(struct Template), 1, mptr);
    fclose(mptr);
    // for (int i = 0; i < 7; i++)
    //{
    //     printf("%-d", template.STEP[i]);
    // }
    // printf("\n");
    // getch();
    mptr = fopen("3.bin", "ab+");
    while (!feof(fptr))
    {
        fread(&temp, sizeof(struct Info), 1, fptr);
        for (int i = 0; i < 3; i++)
        {
            printf("%-d", temp.USER[i]);
        }
        for (int i = 0; i < 3; i++)
        {
            printf("%-d", temp.COLUMN[i]);
        }
        for (int i = 0; i < 3; i++)
        {
            printf("%-d", temp.COLOR[i]);
        }
        fwrite(&temp, sizeof(struct Info), 1, mptr);
        printf("\n---\n");
    }
    fclose(mptr);
    fclose(fptr);

    getch();
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
    printf("   0     1     2     3     4     5     6     7\n");
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
