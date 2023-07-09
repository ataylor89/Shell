#include "StringUtils.h"
#include "Hexdump.h"
#include <iostream>

void print_hexdump(string& Str)
{
    HEXDUMP *dump;
    char *str;
    str = strdup(Str.c_str());
    dump = hexdump(str, strlen(str));
    fwrite(dump->buffer, 1, dump->size, stdout);
    printf("\n");
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return 0;
    }

    string input(argv[1]);

    cout << "User input: " << input << endl;
    print_hexdump(input);

    trim(input);

    cout << "After trim: " << input << endl;
    print_hexdump(input);
    
    return 0;
}