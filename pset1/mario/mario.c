#include<cs50.h>
#include <stdio.h>

int getHeight(void);
void buildTower(int height);
void print(int howManyToPrint, string whatToPrint);

int main(void)
{
    // Get positive input from user between 1 and 8
    int height = getHeight();
    //Print blocks based on height
    buildTower(height);
}

int getHeight(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

void buildTower(int height)
{
    //keep track of current row
    int row = 1;

    //for each row
    while (row <= height)
    {
        //determine number of spaces and hashes in row
        int numberOfSpaces = height - row;
        int numberOfHashes = row;

        string space = " ";
        string hash = "#";

        //print spaces
        print(numberOfSpaces, space);

        //print hashes
        print(numberOfHashes, hash);

        //print space between towers
        print(2, space);

        //print hashes on next tower
        print(numberOfHashes, hash);

        //new line
        printf("\n");
        row++;
    }
}

void print(int howManyToPrint, string whatToPrint)
{
    for (int i = 0; i < howManyToPrint; i++)
    {
        printf("%s", whatToPrint);
    }
}
