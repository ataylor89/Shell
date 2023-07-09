#ifndef SET_PREFIX_H
#define SET_PREFIX_H

#include "Command.h"

class SetPrefix : public Command
{
public:
    SetPrefix(std::string& cmd, Window* window);
    void exec();
};

#endif