#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // if invalid input
    if (argc != 2)
    {
        printf("invalid input");
        return 1;
    }

    // remember filenames
    char *input_file = argv[1];

    // open input file
    FILE *inptr = fopen(input_file, "r");
    if (inptr == NULL)
    {
        printf("memory is empty");
        return 2;
    }

    BYTE buffer[512];
    int image_counter = 0;

    char filename[8];
    FILE *outptr = NULL;

    while (true)
    {
        // read a block of memory card 
        size_t bytes_Readed = fread(buffer, sizeof(BYTE), BLOCK, inptr);

        // break when end the file
        if (bytes_Readed == 0 && feof(inptr))
        {
            break;
        }

        // check if JPEG
        bool if_jpeg = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        // if we found another JPEG, we must close the opened one
        if (if_jpeg && outptr != NULL)
        {
            fclose(outptr);
            image_counter++;
        }

        // if  JPEG, open file for writing photo init
        if (if_jpeg)
        {
            sprintf(filename, "%03i.jpg", image_counter);
            outptr = fopen(filename, "w");
        }

        // write when open file
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytes_Readed, outptr);
        }
    }

    // close last jpeg file
    fclose(outptr);

    // close input_file
    fclose(inptr);

    // success
    return 0;
}
