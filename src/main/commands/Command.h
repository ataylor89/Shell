#ifndef COMMAND_H
#define COMMAND_H

#include "gui/Window.h"

class Command
{
public:
    Command(std::string& user_input, Window* window);
    virtual ~Command();
    virtual void exec() = 0;
protected:
    std::string user_input;
    Window* window;
};

#endif