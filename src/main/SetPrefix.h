#ifndef SET_PREFIX_H
#define SET_PREFIX_H

#include "Window.h"

class SetPrefix : public Command
{
public:
    SetPrefix(std::string& user_input, Window* window);
    void exec();
};

#endif