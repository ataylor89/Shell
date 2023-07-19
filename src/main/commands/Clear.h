#ifndef CLEAR_H
#define CLEAR_H

#include "gui/Window.h"

class Clear : public Command
{
public:
    Clear(std::string& user_input, Window* window);
    void exec();
};

#endif