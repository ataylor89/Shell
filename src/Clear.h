#ifndef CLEAR_H
#define CLEAR_H

#include "Command.h"

class Clear : public Command
{
public:
    Clear(const std::string& cmd, Window* window);
    void exec();
};

#endif