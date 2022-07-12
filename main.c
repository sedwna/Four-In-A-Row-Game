#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 10
void start()
{

    printf("welcome to  ''4 IN A ROW''  game \n"
           "we wish you have a nice time \n"
           "choise what do you want to happen?"
           "1 . (H)ELP\n"
           "2 . (S)TART\n"
           "3 . (E)XIT\n");
    char choise;
    scanf("%c", &choise);
    switch (choise)
    {
    case 'H':
        /* code */
        break;
    case 'S':
        /* code */
        break;
    case 'E':
        /* code */
        break;

    default:
        printf("unknown word!!!\n");
        break;
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
    unsigned int row = 8;
    unsigned int column = 8;
    int array[row][column];
    start();
    // chart();
    // Square();

    /*
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
  */
    return 0;
}
