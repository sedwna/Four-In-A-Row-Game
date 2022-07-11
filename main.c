#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("sajad omad\n");
    char ch;
    unsigned int row = 8;
    unsigned int column = 8;
    int array[row][column];
    while (ch != 'E')
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
    }
    

    

    return 0;
}