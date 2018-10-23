// Implement a program that encrypts messages using Caesar’s cipher
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lower_wraparound(int index, int k);
int upper_wraparound(int index, int k);

int alpha_index = 0;
int enciphered_ascii = 0;

int main(int argc, string argv[])
{
    char enciphered_char;

    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // Convert the key from string to integer
    string key = argv[1];
    int k = atoi(key);

    // Check that user only enters numbers for the key
    if (*key != '0' && k == 0)
    {
        return 1;
    }

    // Get the text to encipher
    string word = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            if (isupper(word[i]))
            {
                enciphered_char = (char)upper_wraparound(word[i], k);
            }
            if (islower(word[i]))
            {
                enciphered_char = (char)lower_wraparound(word[i], k);
            }
            printf("%c", enciphered_char);
        }
        else
        {
            printf("%c", word[i]);
        }
    }
    printf("\n");
}

// Uppercase: Change ascii to alphabetical index, increment by key, and change back to ascii
int upper_wraparound(int c, int k)
{
    alpha_index = c - 65;

    enciphered_ascii = ((alpha_index + k) % 26) + 65;

    return enciphered_ascii;
}

// Lowercase: Change ascii to alphabetical index, increment by key, and change back to ascii
int lower_wraparound(int c, int k)
{
    alpha_index = c - 97;

    enciphered_ascii = ((alpha_index + k) % 26) + 97;

    return enciphered_ascii;
}