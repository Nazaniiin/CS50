
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover file\n");
        return 1;
    }

    char *raw = argv[1];

    // Open image file
    FILE *file = fopen(raw, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Cannot open %s. \n", raw);
        return 2;
    }

    BYTE buffer[512];

    // To check if we have found any jpeg's (0 false and 1 true)
    int jpeg_found = 0;

    // To check the number of the jpeg's found
    int jpeg_count = 0;

    // File to write a jpeg to
    FILE *img = NULL;

    while (!feof(file))
    {
        if (fread(buffer, sizeof(buffer), 1, file) == 1)
        {
            // Check if we have a JPEG image
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                if (jpeg_found == 1)
                {
                    // Close the current image because we have found a new image
                    // The new image needs to be saved in a new file
                    fclose(img);
                } else {
                    // Setting jpeg_found to true
                    jpeg_found = 1;
                }
                char jpgfile[10];
                sprintf(jpgfile, "%03d.jpg", jpeg_count);

                img = fopen(jpgfile, "w");
                jpeg_count++;

                fwrite(buffer, sizeof(buffer), 1, img);
            }
            else if (jpeg_count > 0)
            {
                // Continue writing to the same image file
                // until we reach the end of one jpeg image
                fwrite(buffer, sizeof(buffer), 1, img);
            }
        }
        else
        {
            // We might have no reached the end of file yet
            // but we don't have less than 512 bytes to read
            // for the buffer, hence we break the loop
            break;
        }
    }

    fclose(file);
    fclose(img);

    return 0;
}
