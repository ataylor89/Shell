#ifndef HEXDUMP_H
#define HEXDUMP_H

#include "Window.h"

struct Hexstring
{
    char *buffer;
    int size;
};

class Hexdump : public Command
{
public:
    Hexdump(std::string& user_input, Window* window);
    void exec();
private:
    void exec(const char* filename);
    Hexstring* hexdump(char* str, int size, int line_pos);
    TextView* text_view;
};

#endif