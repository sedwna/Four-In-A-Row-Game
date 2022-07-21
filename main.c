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
int board[size][size];
//****************************************
void EXIT();
bool check_four_nuts(int board[][size], int *num, int *copy_i, int *copy_j, int *first);
void merge(int turn, int bin[]);
void PrintFile();
void Help();
void PrintBoard(int board[][size], int column, int USER, int ColorUser1, int ColorUser2);
void cycle(int turn, int column, int coloruser1, int coloruser2, int bin[]);
int ReConvertB_info(int bin[]);
int ReConvertB_step(int bin[]);
void ConvertB_info(int dec, int bin[3]);
void ConvertB_step(int dec, int bin[7]);
void FRead(int board[][size]);
void FWrite(int user, int column, int color);
void menu(char *choise);
bool check_board(int board[][size]);
void PrintBoard(int board[][size], int column, int USER, int ColorUser1, int ColorUser2);
int ChoiseColumn(int turn, int *column, int bin[]);
void Color(int *ColorUser1, int *ColorUser2);
int Start(int board[][size]);
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
    printf("\n\n\033[0;93mWelcome to  ''4 IN A ROW''  game. \n"
           "we wish you have a nice time...\033[0m \n\n");
    char choise;
    menu(&choise);

    while (1)
    {
        switch (choise)
        {
        case 'p':
        case 'P':
            Start(board);
            break;
        case 's':
        case 'S':
            FRead(board);
            printf("\n \033[0;96mEnter any key to return  menu\033[0m\n");
            getch();
            break;
        case 'h':
        case 'H':
            Help();

            break;
        case 'F':
        case 'f':
            PrintFile();
            printf("\n \033[0;96mEnter any key to return  menu\033[0m\n");
            getch();
            break;
        case 'e':
        case 'E':

            EXIT();
        default:
            printf("\n\033[31m PLS ENTER VALID WORD!!! \033[0m\n");
            break;
        }
        system("cls");
        menu(&choise);
    }

    return 0;
}
//****************************************
void menu(char *choise)
{
    printf(
        "\033[0;91mchoise what do you want to happen?\033[0m\n\n"
        "\033[0;95m1. (H)ELP\033[0m\n"
        "\033[0;32m2. (P)lay\033[0m (to Creat a new game)\n"
        "\033[0;33m3. (S)ave\033[0m (to Continue from last save)\n"
        "\033[0;36m4. (F)ile\033[0m (to Read a save file as '0 & 1' in terminal)  \n"
        "\033[0;31m5. (E)XIT\033[0m\n"
        "\n\033[0;96mEnter choise ---->  \033[0m");
    scanf("%c", choise);
}
//****************************************
void Help()
{

    printf("\n \033[1;35m********\033[0m HELP \033[1;33m4 In a Row \033[1;35m********\n\n"

           "\033[0;36m*your goal is to get four of your pieces\n"
           " to line up in a row before the other player does.\n\n\033[0m");

    printf("press any key to \033[1;32mcontinue\033[0m...\n\n");
    getch();

    printf("\033[0;36m*You choose a game piece color.\n"
           " You'll have several pieces so you're able to fill in the board\n"
           " The board is arranged with empty spaces.\n\n\033[0m");

    printf("press any key to \033[1;32mcontinue\033[0m...\n\n");
    getch();

    printf("\033[0;36m*You and your opponent take turns placing your pieces in those spaces in\n"
           " an effort to connect four of your own pieces in a row\n\n"
           " you can \033[0;31mEXIT\033[0m \033[0;36mever you enter the \033[0;31m(-1)\033[0m \033[0;36min game.\n\033[0m");
    printf("press any key to \033[1;32mcontinue...\n\033[0m");
    getch();
}
//****************************************
int Start(int board[][size])
{
    fptr = fopen("save.bin", "wb");
    fclose(fptr);
    int turn = 1;
    int coloruser1 = -1;
    int coloruser2 = -1;
    int column = -1;
    int bin[7];
    Color(&coloruser1, &coloruser2);
    PrintBoard(board, 0, 0, 0, 0);
    cycle(turn, column, coloruser1, coloruser2, bin);
}
//****************************************
int ChoiseColumn(int turn, int *column, int bin[7])
{
    printf("\033[0;91mExit by enter (-1)\033[0m\n\n");
    do
    {

        if (turn % 2 != 0)
        {
            printf("\033[0;96mTurn USER'1' choise column (0-7) --->\033[0m");
        }
        else
        {
            printf("\033[0;96mTurn USER'2' choise column (0-7) --->\033[0m");
        }
        scanf("%d", column);
        if (*column == -1)
        {
            turn--;
            ConvertB_step(turn, bin);
            merge(turn, bin);
            EXIT();
        }

    } while ((*column > 7 || *column < -1) || board[0][*column] != 0);
}
//****************************************
void Color(int *ColorUser1, int *ColorUser2)
{
    system("cls");
    printf("\033[0;91mExit by enter (-1)\033[0m\n\n");
    // choise color for User 1

    do
    {
        *ColorUser1 = -1;

        printf("\033[0;35mUSER'1'\033[0m \033[0;93mpls choise your color:\033[0m\n\n"
               "\033[0;31mRed(0)\033[0m    \033[0;33mYellow(1)\033[0m    \033[0;32mGreen(2)\033[0m    \033[0;34mBlue(3)\033[0m\n"
               "\n\033[0;96mEnter choise ---->  \033[0m");
        scanf("%d", ColorUser1);
        if (*ColorUser1 == -1)
        {
            EXIT();
        }
    } while (*ColorUser1 >= 4 || *ColorUser1 <= -1);

    // choise color for User 2
    do
    {
        *ColorUser2 = -1;
        printf("\n\033[0;35mUSER'2'\033[0m \033[0;93mpls choise your color:\033[0m\n"
               "\033[0;91myou cant choise same color as the user 1 !!!\033[0m\n\n"
               "\033[0;31mRed(0)\033[0m    \033[0;33mYellow(1)\033[0m    \033[0;32mGreen(2)\033[0m    \033[0;34mBlue(3)\033[0m\n"
               "\n\033[0;96mEnter choise ---->  \033[0m");
        scanf("%d", ColorUser2);
        if (*ColorUser2 == -1)
        {
            EXIT();
        }
    } while (*ColorUser2 >= 4 || *ColorUser2 <= -1);

    // check color 1 vs color 2 to not be same
    do
    {
        if (*ColorUser1 == *ColorUser2)
        {
            printf("\n\033[0;91msame color pls change color \033[0m\033[0;35mUSER'1'\033[0m \033[0;91mor \033[0m\033[0;36mUSER'2'\033[0m\n"
                   "\033[0;93mtell me user number to change color ---> \033[0m ");
            int change = 0;
            scanf("%d", &change);
            if (change == 1)
            {
                *ColorUser1 = -1;
                printf("\n\033[0;93mUSER'1' pls choise your color:\033[0m\n"
                       "\033[0;31mRed(0)\033[0m    \033[0;33mYellow(1)\033[0m    \033[0;32mGreen(2)\033[0m    \033[0;34mBlue(3)\033[0m\n"
                       "\n\033[0;96mEnter choise ---->  \033[0m");
                scanf("%d", ColorUser1);
                if (*ColorUser1 == -1)
                {
                    EXIT();
                }
            }
            else if (change == 2)
            {
                *ColorUser2 = -1;
                printf("\n\033[0;93mUSER'2' pls choise your color:\033[0m\n"
                       "\033[0;91myou cant choise same color as the user 1 !!!\033[0m\n\n "
                       "\033[0;31mRed(0)\033[0m    \033[0;33mYellow(1)\033[0m    \033[0;32mGreen(2)\033[0m    \033[0;34mBlue(3)\033[0m\n"
                       "\n\033[0;96mEnter choise ---->  \033[0m");
                scanf("%d", ColorUser2);
                if (*ColorUser2 == -1)
                {
                    EXIT();
                }
            }
        }

    } while (*ColorUser1 == *ColorUser2);
    system("cls");
}
//****************************************
void EXIT()
{
    system("cls");
    printf("\n\033[0;34m*** until next time, Goodbye ***\033[0m\n");
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
    fptr = fopen("save.bin", "ab+");
    if (fptr == NULL)
    {
        printf("cant open the file\n");
    }

    fwrite(&temp, sizeof(struct Info), 1, fptr);
    fclose(fptr);
    // close File
}
//*****************************************
void FRead(int board[][8])
{
    int bin[7];
    int bin1[3];
    int Step = 0;
    struct Info temp;
    struct Template template;
    int Color1 = -1;
    int Color2 = -1;
    int Column = -1;
    int User = -1;
    int turn = 0;
    mptr = fopen("save2.bin", "rb");
    if (mptr == NULL)
    {
        printf("\033[0;31mcant open the save\033[0m");
        printf("\033[0;91mpress any key to exit...\033[0m\n");
        getch();
        EXIT();
    }
    fread(&template, sizeof(struct Template), 1, mptr);
    for (int i = 0; i < 7; i++)
    {
        bin[i] = template.STEP[i];
    }
    Step = ReConvertB_step(bin);
    turn = Step;
    fread(&temp, sizeof(struct Info), 1, mptr); // read color user 1 from file and save
    for (int i = 0; i < 3; i++)
    {
        bin1[i] = temp.COLOR[i];
    }
    Color1 = ReConvertB_info(bin1);

    fread(&temp, sizeof(struct Info), 1, mptr); // read color user 2 from file and save
    for (int i = 0; i < 3; i++)
    {
        bin1[i] = temp.COLOR[i];
    }
    Color2 = ReConvertB_info(bin1);

    rewind(mptr);
    fread(&template, sizeof(struct Template), 1, mptr);
    while (turn != 0)
    {

        fread(&temp, sizeof(struct Info), 1, mptr);
        for (int i = 0; i < 3; i++)
        {
            bin1[i] = temp.COLUMN[i];
        }
        Column = ReConvertB_info(bin1);
        for (int i = 0; i < 3; i++)
        {
            bin1[i] = temp.USER[i];
        }
        User = ReConvertB_info(bin1);

        system("cls");
        PrintBoard(board, Column, User, Color1, Color2);

        if (check_board(board))
        {
            printf("\n\n\033[0;93mWIN USER '%d'\033[0m \n\n", User);
            printf("\033[0;91mpress any key to exit...\033[0m\n");
            getch();
            EXIT();
        }

        printf("\n \033[0;96mpls enter any key to countinue step --->\033[0m \n");
        getch();
        turn--;
    }
    if (Step == 64)
    {
        Step--;
        ConvertB_step(turn, bin);
        merge(turn, bin);
        printf("\n\n\033[0;93mEqual\033[0m \n\n");
        fptr = fopen("save.bin", "wb");
        fclose(fptr);
        remove("save.bin");
        printf("\033[0;91mpress any key to exit...\033[0m\n");
        getch();
        EXIT();
    }
    printf("\n");
    Step++;

    while (Step != 65)
    {
        cycle(Step, Column, Color1, Color2, bin);
        Step++;
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
    for (int i = 0; i < 7; i++)
    {
        if (bin[i] != 0)
        {
            dec += pow(2, j);
        }
        j--;
    }

    return dec;
}
//*****************************************
int ReConvertB_info(int bin[3])
{

    int dec = 0;
    int j = 2;

    for (int i = 0; i < 3; i++)
    {
        if (bin[i] != 0)
        {
            dec += pow(2, j);
        }
        j--;
    }

    return dec;
}
//*****************************************
void cycle(int turn, int column, int coloruser1, int coloruser2, int bin[7])
{

    while (turn != 65)
    {

        if (turn % 2 != 0)
        {
            ChoiseColumn(turn, &column, bin);
            system("cls");
            PrintBoard(board, column, 1, coloruser1, coloruser2);
            FWrite(1, column, coloruser1);
            if (check_board(board))
            {
                ConvertB_step(turn, bin);
                merge(turn, bin);
                printf("\n\n\033[0;93mWIN USER '1'\033[0m \n\n");
                fptr = fopen("save.bin", "wb");
                fclose(fptr);
                remove("save.bin");
                printf("\033[0;91mpress any key to exit...\033[0m\n");
                getch();
                EXIT();
            }
            turn++;
        }
        else
        {
            ChoiseColumn(turn, &column, bin);
            system("cls");
            PrintBoard(board, column, 2, coloruser1, coloruser2);
            FWrite(2, column, coloruser2);
            if (check_board(board))
            {
                ConvertB_step(turn, bin);
                merge(turn, bin);
                printf("\n\n\033[0;93mWIN USER '2'\033[0m \n\n");
                fptr = fopen("save.bin", "wb");
                fclose(fptr);
                remove("save.bin");
                printf("\033[0;91mpress any key to exit...\033[0m\n");
                getch();
                EXIT();
            }
            turn++;
        }
    }
    turn--;
    ConvertB_step(turn, bin);
    merge(turn, bin);
    printf("\n\n\033[0;93mEqual\033[0m \n\n");
    fptr = fopen("save.bin", "wb");
    fclose(fptr);
    remove("save.bin");
    printf("\033[0;91mpress any key to exit...\033[0m\n");
    getch();
    EXIT();
}
//*****************************************
void merge(int turn, int bin[])
{
    struct Info temp;
    struct Template template;
    mptr = fopen("save2.bin", "wb");
    fptr = fopen("save.bin", "rb");
    for (size_t i = 0; i < 7; i++)
    {
        template.STEP[i] = bin[i];
    }
    fwrite(&template, sizeof(struct Template), 1, mptr);

    rewind(fptr);
    while (!feof(fptr))
    {
        fread(&temp, sizeof(struct Info), 1, fptr);
        fwrite(&temp, sizeof(struct Info), 1, mptr);
    }
}
//*****************************************
void PrintFile()
{
    struct Info temp;
    struct Template template;
    int bin[7];
    int turn;
    mptr = fopen("save2.bin", "rb");
    if (mptr == NULL)
    {
        printf("\033[0;31mcant open the save\033[0m");
        printf("\033[0;91mpress any key to exit...\033[0m\n");
        getch();

        EXIT();
    }

    printf("\n\033[0;96m----------save----------\033[0m\n");
    fread(&template, sizeof(struct Template), 1, mptr);
    for (int i = 0; i < 7; i++)
    {
        bin[i] = template.STEP[i];
    }
    turn = ReConvertB_step(bin);
    for (int i = 0; i < 7; i++)
    {
        printf("%-d", template.STEP[i]);
    }
    printf("\n\n");
    while (turn != 0)
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
        turn--;
    }

    fclose(mptr);
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
                board[i][column] = 1;
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
                board[i][column] = 2;
                break;
            }
        }
    }

    // start
    printf("\033[0;96m   0     1     2     3     4     5     6     7\033[0m \n");
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
                    if (board[i][j] == 1)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[31m%c\033[0m", 219);
                        }
                        printf(" ");
                    }

                    break;
                case 1:
                    if (board[i][j] == 1)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[33m%c\033[0m", 219);
                        }
                        printf(" ");
                    }

                    break;
                case 2:
                    if (board[i][j] == 1)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[32m%c\033[0m", 219);
                        }
                        printf(" ");
                    }

                    break;
                case 3:
                    if (board[i][j] == 1)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[34m%c\033[0m", 219);
                        }
                        printf(" ");
                    }

                    break;
                }

                switch (ColorUser2)
                {
                case 0:
                    if (board[i][j] == 2)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[31m%c\033[0m", 219);
                        }
                        printf(" ");
                    }

                    break;
                case 1:
                    if (board[i][j] == 2)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[33m%c\033[0m", 219);
                        }
                        printf(" ");
                    }

                    break;
                case 2:
                    if (board[i][j] == 2)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[32m%c\033[0m", 219);
                        }
                        printf(" ");
                    }

                    break;
                case 3:
                    if (board[i][j] == 2)
                    {
                        printf(" ");
                        for (int y = 0; y < 3; y++)
                        {
                            printf("\033[34m%c\033[0m", 219);
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
bool check_four_nuts(int board[][size], int *num, int *copy_i, int *copy_j, int *first)
{
    if (*first != 0 && *first == board[*copy_i][*copy_j])
    {
        (*num)++;
    }
    else
    {
        *first = board[*copy_i][*copy_j];
        *num = 0;
    }
    if (*num == 3)
    {
        return true;
    }

    return false;
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
            if (check_four_nuts(board, &num, &copy_i, &copy_j, &first))
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

            if (check_four_nuts(board, &num, &copy_i, &copy_j, &first))
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

            if (check_four_nuts(board, &num, &copy_i, &copy_j, &first))
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

            if (check_four_nuts(board, &num, &copy_i, &copy_j, &first))
            {
                return true;
            }
        } while (copy_j != 7);
    }
    return false;
}