#include <stdio.h>

int main()
{
    unsigned int row = 8;
    unsigned int column = 8;
    int array[row][column];

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

    return 0;
}