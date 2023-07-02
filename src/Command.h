#ifndef COMMAND_H
#define COMMAND_H

#include "Window.h"
#include <string>

class Command
{
public:
    Command(const std::string& cmd, Window* window);
    virtual void exec();
protected:
    std::string cmd;
    Window* window;
};

#endif