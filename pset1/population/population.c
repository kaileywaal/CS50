#include <cs50.h>
#include <stdio.h>


int getMinimumInt(int min, string startOrEnd);
int calculateYears(int startSize, int endSize);


int main(void)
{
    // TODO: Prompt for start size
    int startSize = getMinimumInt(9, "Start");

    // TODO: Prompt for end size
    int endSize = getMinimumInt(startSize, "End");

    // TODO: Calculate number of years until we reach threshold
    int years = calculateYears(startSize, endSize);

    // TODO: Print number of years
    printf("Years: %i\n", years);
}

int getMinimumInt(int min, string startOrEnd)
{
    int n;
    do
    {
        n = get_int("%s size: ", startOrEnd);
    }
    while (n < min);
    return n;
}


//check how many years it takes to grow population
int calculateYears(int startSize, int endSize)
{
    int total = startSize;
    int years = 0;

    while (total < endSize)
    {
        //determine how many llamas are born
        int born = total / 3;

        //determine how many llamas die each year
        int died = total / 4;

        //determine total number of llamas at the end of each year
        total = total + born - died;
        years++;
    }
    return years;
}