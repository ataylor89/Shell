#ifndef CLEAR_H
#define CLEAR_H

#include "gui/Window.h"

class Clear : public Command
{
public:
    Clear(string& cmd, vector<string>& args, Window* window);
    void exec();
private:
    TextView* text_view;
};

#endif