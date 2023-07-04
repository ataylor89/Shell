#ifndef SYSTEM_COMMAND_H
#define SYSTEM_COMMAND_H

#include "Window.h"
#include <string>

class SystemCommand : public Command
{
public:
    SystemCommand(std::string& cmd, Window* window);
    void exec();
};

#endif