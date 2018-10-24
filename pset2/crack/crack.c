// Implement a program that cracks passwords
#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <crypt.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash");
        return 1;
    }
    string hash = argv[1];
    // Based on C's DES crypto algorithm, salt is the first 2 characters in the hash
    char salt[3] = {hash[0], hash[1], '\0'};

    char letters[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
                        'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                        'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
                       };
    // Tests executed successfully:
    // 50xcIMJ0y.RXo --> YES
    // 50mjprEcqC/ts --> CA
    // 50GApilQSG3E2 --> UPenn
    // 50n0AAUD.pL8g --> lloyd
    // 50CcfIk1QrPr6 --> maybe

    // Check all permutations of 1 to 5 letter words
    for (int i = 0; i < 52; i++)
    {
        char pass_1[2] = {letters[i], '\0'};
        if (strcmp(crypt(pass_1, salt), hash) == 0)
        {
            printf("Password is: %s", pass_1);
        }
        for (int j = 0; j < 52; j++)
        {
            char pass_2[3] = {letters[i], letters[j], '\0'};
            if (strcmp(crypt(pass_2, salt), hash) == 0)
            {
                printf("Password is: %s", pass_2);
            }
            for (int q = 0; q < 52; q++)
            {
                char pass_3[4] = {letters[i], letters[j], letters[q], '\0'};
                if (strcmp(crypt(pass_3, salt), hash) == 0)
                {
                    printf("Password is: %s", pass_3);
                }
                for (int z = 0; z < 52; z++)
                {
                    char pass_4[5] = {letters[i], letters[j], letters[q], letters[z], '\0'};
                    if (strcmp(crypt(pass_4, salt), hash) == 0)
                    {
                        printf("Password is: %s", pass_4);
                    }
                    for (int n = 0; n < 52; n++)
                    {
                        char pass_5[6] = {letters[i], letters[j], letters[q], letters[z], letters[n], '\0'};
                        if (strcmp(crypt(pass_5, salt), hash) == 0)
                        {
                            printf("Password is: %s", pass_5);
                        }
                    }
                }
            }
        }
    }
}



