// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool has_lower = false;
    bool has_upper = false;
    bool has_digit = false;
    bool has_symbol = false;

    // Define los caracteres permitidos
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digits = "0123456789";
    string symbols = "!@#$%^&*()-_+={}[]|\\;:'\",.<>/? ";

    // Itera a través de cada carácter en la contraseña y verifica su tipo
    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (strchr(lowercase, password[i]) != NULL)
        {
            has_lower = true;
        }
        else if (strchr(uppercase, password[i]) != NULL)
        {
            has_upper = true;
        }
        else if (strchr(digits, password[i]) != NULL)
        {
            has_digit = true;
        }
        else if (strchr(symbols, password[i]) != NULL)
        {
            has_symbol = true;
        }
    }

    // Verifica si la contraseña contiene al menos un carácter de cada tipo
    if (has_lower && has_upper && has_digit && has_symbol)
    {
        return true;
    }
    else
    {
        return false;
    }
}
