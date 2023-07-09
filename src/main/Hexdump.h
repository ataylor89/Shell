#ifndef HEX_DUMP_H
#define HEX_DUMP_H

#include <string>

using namespace std;

typedef struct
{
    char *buffer;
    int size;
} HEXDUMP;

HEXDUMP* hexdump(char* str, int size);
void print_hexdump(char* str, int size);
void print_hexdump(string& str);

#endif