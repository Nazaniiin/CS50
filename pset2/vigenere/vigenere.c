// Implement a program that encrypts messages using Vinegere’s cipher
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int key_wraparound(char k);
int lower_wraparound(char c, char k);
int upper_wraparound(char c, char k);

// Store the alpha index of a given character in plaintext
int alpha_index = 0;

// Store the alhpa index of a given character in the key
int key_alpha_index = 0;

int enciphered_ascii = 0;

int main(int argc, string argv[])
{
    // Store the enciphered for a given character in plaintext
    char enciphered_char;

    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    // Check that the key doesn't contain any non-alphabetical characters
    string key = argv[1];
    for (int m = 0; m < strlen(key); m++)
    {
        if (!isalpha(key[m]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }
    // Get the text to encipher
    string word = get_string("plaintext: ");

    printf("ciphertext: ");
    // Get position of characters in the plaintext
    for (int i = 0, j = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            // Get position of characters in the key
            int k = (j % strlen(key));

            if (isupper(word[i]))
            {
                printf("%c", (char)upper_wraparound(word[i], key[k]));
                j++;
            }
            if (islower(word[i]))
            {
                printf("%c", (char)lower_wraparound(word[i], key[k]));
                j++;
            }
        }
        else
        {
            printf("%c", word[i]);
        }
    }
    printf("\n");
}

// Get the alpha index of the characters in key
int key_wraparound(char k)
{
    int index = 0;

    if (isupper(k))
    {
        index = k - 65;
    }
    if (islower(k))
    {
        index = k - 97;
    }
    return index;
}

// Uppercase: Change ascii to alphabetical index, increment by key, and change back to ascii
int upper_wraparound(char c, char k)
{
    alpha_index = c - 65;
    key_alpha_index = key_wraparound(k);

    enciphered_ascii = ((alpha_index + key_alpha_index) % 26) + 65;

    return enciphered_ascii;
}

// Lowercase: Change ascii to alphabetical index, increment by key, and change back to ascii
int lower_wraparound(char c, char k)
{
    alpha_index = c - 97;
    key_alpha_index = key_wraparound(k);

    enciphered_ascii = ((alpha_index + key_alpha_index) % 26) + 97;

    return enciphered_ascii;
}