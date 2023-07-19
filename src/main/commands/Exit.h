#ifndef EXIT_H
#define EXIT_H

#include "gui/Window.h"

class Exit : public Command
{
public:
    Exit(std::string& user_input, Window* window);
    void exec();
};

#endif