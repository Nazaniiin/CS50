// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: Resize scale infile outfile\n");
        return 1;
    }

    float f = atof(argv[1]);

    if (f < 0 || f > 100)
    {
        fprintf(stderr, "Resize scale should be between 0-100\n");
        return 2;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Metadata for the resized image
    BITMAPFILEHEADER bf_resize = bf;
    BITMAPINFOHEADER bi_resize = bi;

    // Width and Height for the resized image
    bi_resize.biHeight *= floor(f);
    bi_resize.biWidth *= floor(f);

    float f2 = floor(f);
    printf("f2 %f\n", f2);
    printf("bi_resize.biHeight %d\n", bi_resize.biHeight);
    printf("bi_resize.biWidth %d\n", bi_resize.biWidth);

    // Padding for the resized image
    int padding_resize = (4 - (bi_resize.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // ImageSize for the resized image
    bi_resize.biSizeImage = ((sizeof(RGBTRIPLE) * bi_resize.biWidth) + padding_resize) * abs(bi_resize.biHeight);

    // bfSize for the resized image
    bf_resize.bfSize = bi_resize.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_resize, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_resize, sizeof(BITMAPINFOHEADER), 1, outptr);

    // temporary storage
    RGBTRIPLE triple[abs(bi.biHeight)][bi.biWidth];

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // read RGB triple from infile
            fread(&triple[i][j], sizeof(RGBTRIPLE), 1, inptr);
        }
        for (int r = 0; r < f; r++)
        {
            for (int j = 0; j < bi.biWidth; j++)
            {
                for (int m = 0; m < f; m++)
                    {
                        // write RGB triple to outfile
                        fwrite(&triple[i][j], sizeof(RGBTRIPLE), 1, outptr);
                    }
            }
            // then add it back (to demonstrate how)
            for (int k = 0; k < padding_resize; k++)
            {
                fputc(0x00, outptr);
            }
        }
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
