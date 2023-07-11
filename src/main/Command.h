#ifndef COMMAND_H
#define COMMAND_H

#include "Window.h"

class Command
{
public:
    Command(std::string& cmd, Window* window);
    virtual ~Command();
    virtual void exec() = 0;
protected:
    std::string cmd;
    Window* window;
};

#endif