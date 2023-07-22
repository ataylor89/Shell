#ifndef EXIT_H
#define EXIT_H

#include "gui/Window.h"

class Exit : public Command
{
public:
    Exit(string& cmd, vector<string>& args, Window* window);
    void exec();
};

#endif