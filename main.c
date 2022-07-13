#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define row 8
#define column 8

void printarr(int array[][column])
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            printf("%d  ", array[i][j]);
        }
        puts(" ");
    }
}

bool check_board(int array[][column])
{
    int i;
    int j;

    for (i = 0; i < row; i++) // check kardane satrha
    {
        int num = 0;

        for (j = 0; j < column; j++)
        {
            if (array[i][j] == array[i][j + 1] && array[i][j] != 0)
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

    for (size_t j = 0; j < column; j++) // cheack kardane sotonha
    {
        int num = 0;

        for (size_t i = 0; i < row; i++)
        {
            if (array[i][j] == array[i + 1][j] && array[i][j] != 0)
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
    return false;
}

void user_1(int array[][column])
{
    int i;
    int j;
    scanf("%d", &j);

    for (i = 7; i >= 0 && array[i][j] != 0; i--);
        
    array[i][j] = 1;

    system("cls");
    printarr(array);

    if(check_board(array))
    {
        printf("win user1\n");
    }
}

void user_2(int array[][column])
{
    int i;
    int j;
    scanf("%d", &j);

    for (i = 7; i >= 0 && array[i][j] != 0; i--);
       
    array[i][j] = 2;

    system("cls");
    printarr(array);

    if(check_board(array))
    {
        printf("win user2\n");
    }
}

void play(int array[][column])
{
    for (size_t step = 1; step <= 64; step++)
    {
        if (step % 2 != 0)
        {
            user_1(array);
        }

        if (step % 2 == 0)
        {
            user_2(array);
        }
    }
}




int main()
{
    int array[8][8] = {0};

    play(array);
    return 0;
}
/*
    int i = 3, j = 0;

    for (size_t k = 1; k <= 9; k++) // cheack kardane ghotrhaye asli
    {
        if (k % 2 != 0)
        {
            x = array[i][j];
            do
            {
                i--;
                j++;
                if (array[i][j] == x)
                {
                    num++;
                }

                else
                {
                    x = array[i][j];
                    num = 0;
                }

                if (num == 3)
                {
                    return true;
                }

            } while (i != 0);

            if (k < 5)
            {
                j++;
            }
            if (k >= 5)
            {
                i++;
            }
        }

        if (k % 2 == 0)
        {
            x = array[i][j];
            do
            {
                i++;
                j--;
                if (array[i][j] == x)
                {
                    num++;
                }

                else
                {
                    x = array[i][j];
                    num = 0;
                }

                if (num == 3)
                {
                    return true;
                }

            } while (j != 0);

            if (k < 5)
            {
                i++;
            }
            if (k > 5)
            {
                j++;
            }
        }
    }

    i = 4, j = 0;

    for (size_t k = 1; k <= 9; k++) // cheack kardane ghotrhaye fari
    {
        if (k % 2 != 0)
        {
            x = array[i][j];
            do
            {
                i++;
                j++;
                if (array[i][j] == x)
                {
                    num++;
                }

                else
                {
                    x = array[i][j];
                    num = 0;
                }

                if (num == 3)
                {
                    return true;
                }

            } while (i != 7);

            if (k < 5)
            {
                j++;
            }
            if (k >= 5)
            {
                i--;
            }
        }

        if (k % 2 == 0)
        {
            x = array[i][j];
            do
            {
                i--;
                j--;
                if (array[i][j] == x)
                {
                    num++;
                }

                else
                {
                    x = array[i][j];
                    num = 0;
                }

                if (num == 3)
                {
                    return true;
                }

            } while (j != 0);

            if (k < 5)
            {
                i--;
            }
            if (k >= 5)
            {
                j++;
            }
        }
    }

    return false;
}*/