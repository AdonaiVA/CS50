// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    double bill_amount = get_double("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    float tip_percent = get_float("Tip percent: ");

    double amount = bill_amount + (bill_amount * (tax_percent / 100));
    double total = amount + ( amount * (tip_percent/100));
    float half = (total / 2);

    printf("You will owe $%0.2f each!\n", half);
}

// TODO: Complete the function