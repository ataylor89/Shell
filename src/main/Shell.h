#ifndef SHELL_H
#define SHELL_H

#include "Window.h"

class Shell
{
public:
    Shell(Window* window);
    void exec(std::string command);
private:
    Window* window;
};

#endif