#ifndef COMMAND_H
#define COMMAND_H

#include "gui/Window.h"
#include <vector>
#include <string>

using namespace std;

class Command
{
public:
    Command(string& cmd, vector<string>& args, Window* window);
    virtual ~Command();
    virtual void exec() = 0;
protected:
    string cmd;
    vector<string> args;
    Window* window;
};

#endif