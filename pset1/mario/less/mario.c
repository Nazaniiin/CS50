#include <cs50.h>
#include <stdio.h>

bool check_height(int n);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

    // Generate the half-pyramid once user input is correct
    for (int i = 1; i <= height; i++)
    {
        for (int j = height; j > i ; j--)
        {
            printf(" ");
        }
        for (int z = 0; z <= i; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}
