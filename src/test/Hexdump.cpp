#include "Util.h"
#include <cstdio>
#include <cstring>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return 0;
    }

    print_hexdump(argv[1], strlen(argv[1]));

    return 0;
}