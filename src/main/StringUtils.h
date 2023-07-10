#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <vector>
#include <string>

using namespace std;

typedef struct {
    char *buffer;
    int size;
} HEXDUMP;

vector<string> split(string& str, const string& delimiters);

vector<string> split(string& str, const string& delimiters, int limit);

string trim(string& str);

HEXDUMP* hexdump(char* str, int size, int line_pos = 0);

HEXDUMP* hexdump(string& str, int line_pos = 0);

void print_hexdump(char* str, int size);

void print_hexdump(std::string& str);

#endif