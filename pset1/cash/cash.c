#include <cs50.h>
#include <math.h>
#include <stdio.h>

float getChangeOwed(void);
int countChange(int changeDue);
int countCoinsNeeded(int coinValue, int changeDue);

int main(void)
{
    // get float for change owed
    float changeOwed = getChangeOwed();

    // convert float from dollars to cents
    int change = round(changeOwed * 100);

    // check how many of each coin is needed (starting with highest value)
    int coinsNeeded = countChange(change);

    // print number of coins needed
    printf("%i\n", coinsNeeded);
}

float getChangeOwed(void)
{
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change <= 0);
    return change;
}

int countChange(int changeDue)
{
    int coinsNeeded = 0;

    do
    {
        //determine how many of each type of coins are needed
        int quarters = countCoinsNeeded(25, changeDue);
        changeDue -= quarters * 25;

        int dimes = countCoinsNeeded(10, changeDue);
        changeDue -= dimes * 10;

        int nickels = countCoinsNeeded(5, changeDue);
        changeDue -= nickels * 5;

        int pennies = countCoinsNeeded(1, changeDue);
        changeDue -= pennies * 1;

        //count up total number of coins needed
        coinsNeeded = quarters + dimes + nickels + pennies;
    }
    while (changeDue > 0);

    return coinsNeeded;
}

int countCoinsNeeded(int coinValue, int changeDue)
{
    int coins = 0;

    while (changeDue >= coinValue)
    {
        changeDue -= coinValue;
        coins++;
    }

    return coins;
}