#include <stdio.h>
#include <cs50.h>
#include <math.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents = get_cents();

    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    int pennies = calculate_pennies(cents);

    int total_coins = quarters + dimes + nickels + pennies;

    printf("%i\n", total_coins);
}

int get_cents(void)
{
    int cents;

    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    return cents;
}

int calculate_quarters(int cents)
{
    return floor(cents / 25);
}

int calculate_dimes(int cents)
{
    cents = cents % 25;
    return floor(cents / 10);
}

int calculate_nickels(int cents)
{
    cents = cents % 10;
    return floor(cents / 5);
}

int calculate_pennies(int cents)
{
    cents = cents % 5;
    return cents;
}
