#include <cs50.h>
#include <stdio.h>

int main(void)
{

// Get heigth
    int h;
    do
    {
        h = get_int("Heigth: ");
    }
    while (h < 1 || h > 8);

    // Print blocks and dots
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= h - i; j++)
        {
            printf(" ");
        }
        for (int a = 1; a <= i; a++)
        {
            printf("#");
        }
        printf("\n");
    }
}