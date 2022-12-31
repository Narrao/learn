#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    int i = 0,j = 0,t = 0;

    Sleep(500);
    
   printf("          ****                  ****\n");

   Sleep(500);

   printf("      ************          ************\n");

   Sleep(500);

   printf("    ****************      ****************\n");
   
   Sleep(500);

   printf("  ********************  ********************\n");

   Sleep(500);

   printf("  ******************************************\n");

   Sleep(500);

   for (int i = 0; i < 7; i++)
   {
        printf("**********************************************\n");

        Sleep(500);
   }
   for (int i = 1; i < 4; i++)
   {
        for (int j = 1; j <= i; j++)
        {
            printf("  ");
        }
        for (int t = 1; t <= 23 - 2 * i; t++)
        {
            printf("**");
        }
        printf("\n");

        Sleep(500);

        for (int j = 1; j <= i; j++)
        {
            printf("  ");
        }
        for (int t = 1; t <= 23 - 2 * i; t++)
        {
            printf("**");
        }
        printf("\n");

        Sleep(500);
        
   }
   for (int i = 1; i <= 8; i++)
   {
        for (int j = 0; j < i + 3; j++)
        {
            printf("  ");
        }
        for (int t = 0; t < 17 - 2 * i; t++)
        {
            printf("**");
        }
        printf("\n");

        Sleep(500);
   }
   system("pause");
}