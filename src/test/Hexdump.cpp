#include "Hexdump.h"
#include <cstdio>
#include <cstring>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return 0;
    }

    HEXDUMP *dump;

    dump = hexdump(argv[1], strlen(argv[1]));

    fwrite(dump->buffer, 1, dump->size, stdout);

    return 0;
}