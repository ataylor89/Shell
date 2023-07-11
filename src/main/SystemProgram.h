#ifndef SYSTEM_PROGRAM_H
#define SYSTEM_PROGRAM_H

#include "Window.h"

class SystemProgram : public Command
{
public:
    SystemProgram(std::string& cmd, Window* window);
    void exec();
};

#endif