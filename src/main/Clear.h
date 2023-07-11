#ifndef CLEAR_H
#define CLEAR_H

#include "Window.h"

class Clear : public Command
{
public:
    Clear(std::string& cmd, Window* window);
    void exec();
};

#endif