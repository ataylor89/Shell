#ifndef HEXDUMP_H
#define HEXDUMP_H

#include "Command.h"

class Hexdump : public Command
{
public:
    Hexdump(std::string& cmd, Window* window);
    void exec();
private:
    void _exec(const char* filename);
    TextView* text_view;
};

#endif