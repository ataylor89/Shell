#ifndef CD_H
#define CD_H

#include "gui/Window.h"

class Cd : public Command
{
public:
    Cd(string& cmd, vector<string>& args, Window* window);
    void exec();
private:
    TextView* text_view;
};

#endif