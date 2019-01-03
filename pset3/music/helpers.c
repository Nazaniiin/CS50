// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // Parse the duration by dividing the elements before and after the /
    int nominator = atoi(&fraction[0]);
    int denominator = atoi(&fraction[2]);
    int dur = (nominator*8) / denominator;

    return dur;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int counter = 0;
    int acc_count = 0;
    char accidental;
    char letter;
    int octave = 0;
    int freq = 0;

    // Notes with accidentals
    if (strlen(note) == 3)
    {
        // Parse a note to take out the letter, possible accidental and its octave
        letter = note[0];
        accidental = note[1];
        if (accidental == '#')
        {
            acc_count = 1;
        }
        else if (accidental == 'b')
        {
            acc_count = -1;
        }
        octave = atoi(&note[2]);
    } // Notes without accidentals
    else
    {
        letter = note[0];
        octave = atoi(&note[1]);
        // Don't increment the accidental if the note only consists of a letter and an octave
        acc_count = 0;
    }

    // Space between piano keys in one octave
    if (letter == 'A')
    {
        counter = 0;
    }
    else if (letter == 'B')
    {
        counter += 2;
    }
    else if (letter == 'C')
    {
        counter -= 9;
    }
    else if (letter == 'D')
    {
        counter -= 7;
    }
    else if (letter == 'E')
    {
        counter -= 5;
    }
    else if (letter == 'F')
    {
        counter -= 4;
    }
    else if (letter == 'G')
    {
        counter -= 2;
    }

    // Calculate the frequency based on octave and accidental of a note
    float power = (float)((octave - 4) * 12 + counter + acc_count) / 12;
    freq = round(440 * pow(2, power));

    return freq;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
