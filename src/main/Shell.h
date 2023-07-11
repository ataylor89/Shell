#ifndef SHELL_H
#define SHELL_H

#include "Window.h"

class Shell
{
public:
    Shell(Window* window);
    void exec(std::string command);
    Parser* get_parser();
private:
    Window* window;
    TextView* text_view;
    Parser* parser;
};

#endif