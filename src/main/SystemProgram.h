#ifndef SYSTEM_PROGRAM_H
#define SYSTEM_PROGRAM_H

#include "Window.h"
#include <string>

using namespace std;

class SystemProgram : public Command
{
public:
    SystemProgram(string& cmd, Window* window);
    void exec();
};

#endif