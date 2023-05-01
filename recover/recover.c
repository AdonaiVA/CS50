#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Check if the program is called with exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    // Open the file containing the forensics image
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Set up variables to keep track of recovered file information
    int count = 0;
    char filename[8];
    FILE *img = NULL;

    // Set up buffer for reading blocks of data from the forensics image
    uint8_t buffer[BLOCK_SIZE];

    // Read blocks of data from the forensics image until the end of the file is reached
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        // Check if the block of data is the start of a new JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close any previous JPEG file
            if (img != NULL)
            {
                fclose(img);
            }

            // Generate a filename for the new JPEG file
            sprintf(filename, "%03d.jpg", count);
            count++;

            // Open the new JPEG file for writing
            img = fopen(filename, "w");
            if (img == NULL)
            {
                fclose(file);
                printf("Could not create %s.\n", filename);
                return 1;
            }
        }

        // Write the block of data to the current JPEG file (if one is open)
        if (img != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    }

    // Close any open files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(file);

    // Exit indicating success
    return 0;
}
