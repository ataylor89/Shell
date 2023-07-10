#include "StringUtils.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

vector<string> split(string& Str, const string& Delimiters)
{
    vector<string> buffer;
    char *str, *token;
    const char *delimiters;

    str = strdup(Str.c_str());
    delimiters = Delimiters.c_str();

    token = strtok(str, delimiters);

    while (token)
    {
        buffer.push_back(token);
        token = strtok(NULL, delimiters);
    }

    return buffer;
}

vector<string> split(string& Str, const string& Delimiters, int limit)
{
    vector<string> buffer;

    if (limit <= 1)
    {
        buffer.push_back(Str);
        return buffer;
    }

    char *str, *token;
    const char *delimiters;

    str = strdup(Str.c_str());
    delimiters = Delimiters.c_str();

    if ((token = strtok(str, delimiters)))
    {
        buffer.push_back(token);
        limit--;
    }
    
    while (limit > 1 && (token = strtok(NULL, delimiters)))
    {
        buffer.push_back(token);
        limit--;
    }

    if ((token = strtok(NULL, "")))
    {
        buffer.push_back(token);
    }
    
    return buffer;
}

string trim(string& str)
{
    size_t pos;

    pos = str.find_first_not_of(' ');

    if (pos > 0)
    {
        str.erase(0, pos);
    }

    pos = str.find_last_not_of(' ');

    if (pos < str.length() - 1)
    {
        str.erase(pos + 1, str.length() - 1 - pos);
    }

    return str;
}

HEXDUMP* hexdump(char* str, int size, int line_pos)
{
    HEXDUMP *dump;
    char *ptr;
    int i, j, num_spaces;

    dump = (HEXDUMP *) malloc(sizeof(HEXDUMP));
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

HEXDUMP* hexdump(std::string& Str)
{
    char *str;
    str = strdup(Str.c_str());
    return hexdump(str, Str.length());
}

void print_hexdump(char *str, int size)
{
    HEXDUMP* dump;
    dump = hexdump(str, size);
    fwrite(dump->buffer, 1, dump->size, stdout);
}

void print_hexdump(std::string& Str)
{
    char *str;
    str = strdup(Str.c_str());
    print_hexdump(str, Str.length());
}