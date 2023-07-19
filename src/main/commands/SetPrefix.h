#ifndef SET_PREFIX_H
#define SET_PREFIX_H

#include "gui/Window.h"

class SetPrefix : public Command
{
public:
    SetPrefix(string& cmd, vector<string>& args, Window* window);
    void exec();
private:
    TextView* text_view;
    Settings* settings;
};

#endif