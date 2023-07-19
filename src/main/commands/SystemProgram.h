#ifndef SYSTEM_PROGRAM_H
#define SYSTEM_PROGRAM_H

#include "gui/Window.h"

class SystemProgram : public Command
{
public:
    SystemProgram(std::string& user_input, Window* window);
    void exec();
private:
    TextView* text_view;
};

#endif