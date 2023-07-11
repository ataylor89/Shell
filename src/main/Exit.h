#ifndef EXIT_H
#define EXIT_H

#include "Window.h"

class Exit : public Command
{
public:
    Exit(std::string& cmd, Window* window);
    void exec();
};

#endif