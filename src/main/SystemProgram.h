#ifndef SYSTEM_COMMAND_H
#define SYSTEM_COMMAND_H

#include "Window.h"
#include <string>

class SystemProgram : public Command
{
public:
    SystemProgram(std::string& cmd, Window* window);
    void exec();
};

#endif