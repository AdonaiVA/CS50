#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start population: ");
    }
    while (start < 9);
    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End population: ");
    }
    while (end < start);
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    do
    {
        float a = start / 3;
        float b = start / 4;
        start = start + a - b;
        years ++;
    }
    while (start < end);

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
