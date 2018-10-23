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

    // Print the left-side pyramid
    for (int i = 1; i <= height; i++)
    {
        for (int j = height; j > i ; j--)
        {
            printf(" ");
        }
        for (int z = 1; z <= i; z++)
        {
            printf("#");
        }
        // Insert the space
        printf("  ");

        // Print the right-side pyramid
        for (int q = 0; q < i; q++)
        {
            printf("#");
        }
        printf("\n");
    }
}
