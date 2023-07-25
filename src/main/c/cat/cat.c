#include "cat.h"
#include <stdio.h>

int cat(char* filename)
{
    FILE* file;
    int offset, filesize, n;
    char buffer[PARTITION_LENGTH];

    if ((file = fopen(filename, "r")) == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    offset = 0;
    fseek(file, 0, SEEK_END);
    filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    while (offset < filesize)
    {
        n = (filesize - offset) < PARTITION_LENGTH ? filesize - offset : PARTITION_LENGTH;
         
        if (fread(buffer, 1, n, file) != n)
        {
            printf("Error reading from file.\n");
            return 1;
        }

        fwrite(buffer, 1, n, stdout);
        offset += n;
    }

    fclose(file);
    return 0;
}

int main(int argc, char** argv)
{
    int exit_code;

    if (argc == 2)
    {
        exit_code = cat(argv[1]);
    }

    else
    {
        printf("Usage: %s <filename>\n", argv[0]);
        exit_code = 0;
    }
    
    return exit_code;
}