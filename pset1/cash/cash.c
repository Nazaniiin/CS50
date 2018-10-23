#include <cs50.h>
#include <stdio.h>
#include <math.h>

float quarter = 25;
float dime = 10;
float nickel = 5;
float penny = 1;
int change = 0;

int main(void)
{
    float dollar;
    do
    {
        dollar = get_float("Change owed: ");
    }
    while (dollar < 0);

    // Convert dollar to cents
    float cents = round(dollar * 100);

    // Write the greedy cashier calculations
    while (cents >= 0)
    {
        if (cents - quarter >= 0)
        {
            cents = cents - quarter;
            change += 1;
        }
        else if (cents - dime >= 0)
        {
            cents = cents - dime;
            change += 1;
        }
        else if (cents - nickel >= 0)
        {
            cents = cents - nickel;
            change += 1;
        }
        else if (cents - penny >= 0)
        {
            cents = cents - penny;
            change += 1;
        }
        else
        {
            break;
        }
    }
    printf("%d", change);
    printf("\n");
}

