#ifndef COMMAND_H
#define COMMAND_H

#include "gui/Window.h"
#include <vector>
#include <string>

class Command
{
public:
    Command(std::string& user_input, Window* window);
    virtual ~Command();
    virtual void exec() = 0;
protected:
    void preprocess(std::vector<std::string>& args);
    std::string user_input;
    Window* window;
    Settings* settings;
};

#endif