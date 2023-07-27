#include "cat.h"
#include <stdio.h>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 0;
    }

    return cat(argv[1]);
}