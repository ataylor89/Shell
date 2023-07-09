#include "Hexdump.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

HEXDUMP* hexdump(char* str, int size)
{
    HEXDUMP *dump;
    char *ptr;
    int i, j, line_pos, num_spaces;

    dump = (HEXDUMP *) malloc(sizeof(HEXDUMP));
    dump->buffer = (char *) malloc(sizeof(char) * size * 10);
    ptr = dump->buffer;
    line_pos = 0;

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

void print_hexdump(char *str, int size)
{
    HEXDUMP* dump;
    dump = hexdump(str, size);
    fwrite(dump->buffer, 1, dump->size, stdout);
}

void print_hexdump(string& Str)
{
    char *str;
    str = strdup(Str.c_str());
    print_hexdump(str, Str.length());
}