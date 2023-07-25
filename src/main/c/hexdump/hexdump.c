#include "hexdump.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

Hexdump* hexdump(char* str, int size, int line_pos)
{
    Hexdump *dump;
    char *ptr;
    int i, j, num_spaces;

    dump = (Hexdump *) malloc(sizeof(Hexdump));
    dump->buffer = (char *) malloc(sizeof(char) * size * 10);
    ptr = dump->buffer;

    for (i = 0; i < size;)
    {
        sprintf(ptr, "%08x: ", line_pos);

        ptr += 10;

        for (j = 0; j < 16; j++)
        { 
            if (i + j > size - 1)
            {
                num_spaces = (j % 2 == 1) ? 3 : 2;
                sprintf(ptr, "%*c", num_spaces, ' ');
                ptr += num_spaces;
            }
            else if (j % 2 == 1)
            {
                sprintf(ptr, "%02hhx ", str[i + j]);
                ptr += 3;
            }
            else
            {
                sprintf(ptr, "%02hhx", str[i + j]);
                ptr += 2;
            }
        }

        for (j = 0; j < 16 && i + j < size; j++)
        {
            char ch = isprint(str[i + j]) ? str[i + j] : '.';
            if (j == 15 && i + j < size - 1)
            {
                sprintf(ptr, "%c\n", ch);
                ptr += 2;
            }
            else
            {
                sprintf(ptr, "%c", ch);
                ptr++;
            }
        }

        i += j;
        line_pos += 16;
    }

    dump->size = ptr - dump->buffer;
    return dump;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        putc(EOF, stdout);
        return 0;
    }

    Hexdump *dump;
    FILE *file;
    int offset, filesize, n;
    char *buffer;

    if ((file = fopen(argv[1], "r")) == NULL)
    {
        printf("Error opening file.\n");
        putc(EOF, stdout);
        return 1;
    }

    offset = 0;
    fseek(file, 0, SEEK_END);
    filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (char *) malloc(PARTITION_LENGTH);

    while (offset < filesize)
    {
        n = (filesize - offset) < PARTITION_LENGTH ? filesize - offset : PARTITION_LENGTH;

        if (fread(buffer, 1, n, file) != n)
        {
            printf("Error reading from file.\n");
            putc(EOF, stdout);
            return 1;
        }

        dump = hexdump(buffer, n, offset);
        fwrite(dump->buffer, 1, dump->size, stdout);

        offset += n;

        if (offset < filesize)
        {
            printf("\n*\n");
        }
    }

    putc(EOF, stdout);
    fclose(file);
    return 0;
}