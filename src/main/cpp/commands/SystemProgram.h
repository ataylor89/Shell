#ifndef SYSTEM_PROGRAM_H
#define SYSTEM_PROGRAM_H

#include "gui/Window.h"

class SystemProgram : public Command
{
public:
    SystemProgram(string& cmd, vector<string>& args, Window* window);
    void exec();
private:
    TextView* text_view;
};

#endif