#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 10
void chart()
{
    // start
    printf("\033[96m%c\033[0m", 43);
    for (size_t i = 0; i < SIZE * 4 -1; i++)
        printf("\033[96m%c\033[0m", 45);
    printf("\033[96m%c\033[0m \n", 43); // end start
    for (size_t j = 0; j < 8; j++)
    {

        // start mid
        for (size_t i = 0; i < SIZE - 1; i++)
        {
            printf("%c", 179);
            printf("    ");
        }
        printf("\n"); // end mid

        // finish
        printf("%c", 43);
        for (size_t i = 0; i < SIZE *4 -1; i++)
            printf("%c", 45);
        printf("%c\n", 43); // end finish
    }
}

           
int main()
{
    char ch;
    unsigned int row = 8;
    unsigned int column = 8;
    int array[row][column];
    chart();
    /*while (ch != 'E')
    {
        for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            array[row][column] = 0;
        }
    }

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            printf("%d ", array[row][column]);
        }
        printf("\n");
    }
    ch = getch();
    system("cls");



    }*/

    return 0;
}