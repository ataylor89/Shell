#ifndef HEXDUMP_H
#define HEXDUMP_H

#include "Window.h"

class Hexdump : public Command
{
public:
    Hexdump(std::string& user_input, Window* window);
    void exec();
private:
    void exec(const char* filename);
    TextView* text_view;
};

#endif