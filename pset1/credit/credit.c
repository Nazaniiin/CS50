// Take user's credit card number and check if it's a valid card.

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_length(long long number);
bool checksum(long long number);
bool is_amex(long long number);
bool is_master(long long number);
bool is_visa(long long number);
int get_every_other_digit(int arr[], long long number);

int digit_length = 0;

int main(void)
{
    long long credit_number;
    do
    {
        credit_number = get_long_long("Number: ");
    }
    while (credit_number <= 0);

    if (!checksum(credit_number))
    {
        printf("INVALID");
        printf("\n");
    }
    else
    {
        if (is_amex(credit_number))
        {
            printf("AMEX");
            printf("\n");
        }

        else if (is_master(credit_number))
        {
            printf("MASTERCARD");
            printf("\n");
        }

        else if (is_visa(credit_number))
        {
            printf("VISA");
            printf("\n");
        }
        else
        {
            printf("INVALID");
            printf("\n");
        }
    }
}

bool checksum(long long number)
{
    int i = 0;
    int digit[20];
    int count = 0;
    int sum_other_digits = 0;
    int every_other_digit = 0;
    int sum_every_other_digit = 0;
    int sum_all_digits = 0;

    long long previous_number = number;

    while (number)
    {
        digit[count] = previous_number % 10;

        // Take out every other digit after the second-to-last digit
        if (count % 2 != 0)
        {
            every_other_digit = digit[count] * 2;
            // Add the products' digits together
            if (every_other_digit < 10)
            {
                sum_every_other_digit = sum_every_other_digit + every_other_digit;
            }
            else if (every_other_digit >= 10)
            {
                int first = every_other_digit / 10;
                int second = every_other_digit % 10;
                sum_every_other_digit = sum_every_other_digit + first + second;
            }
        } // Get sum of the digits that weren't multiplied by 2
        else
        {
            sum_other_digits = sum_other_digits + digit[count];
        }
        number = previous_number / 10;
        previous_number = number;
        count++;
    }
    // Add the two sums together
    sum_all_digits = sum_every_other_digit + sum_other_digits;

    // If last digit is zero, number is valid
    if (sum_all_digits % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Get the length of the credit card number
int get_length(long long number)
{
    int length = 1;
    while (number /= 10)
    {
        length++;
    }
    return length;
}

// 15 digits, starts with 34 or 37
bool is_amex(long long number)
{
    int first_2_digit = number / pow(10, 13);
    digit_length = get_length(number);

    if (digit_length == 15)
    {
        if (first_2_digit == 34 || first_2_digit == 37)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// 16 digits, starts with 51, 52, 53, 54, or 55
bool is_master(long long number)
{
    int first_2_digit = number / pow(10, 14);
    digit_length = get_length(number);

    if (digit_length == 16)
    {
        if (first_2_digit == 51 || first_2_digit == 52 || first_2_digit == 53 || first_2_digit == 54 || first_2_digit == 55)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// 13 or 16 digits, starts with 4
bool is_visa(long long number)
{
    int first_digit_13 = number / pow(10, 12);
    int first_digit_16 = number / pow(10, 15);
    digit_length = get_length(number);

    if (digit_length == 16 || digit_length == 13)
    {
        if (first_digit_13 == 4 || first_digit_16 == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}