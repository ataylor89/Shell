#ifndef PARSER_H
#define PARSER_H

#include "gui/Window.h"
#include "commands/Command.h"
#include "parser/CmdMap.h"

class Parser
{
public:
    Parser(Window* window);
    Command* parse(string& cmd);
private:
    void replace_tilde(vector<string>& args);
    Window* window;
    Settings* settings;
    CmdMap cmdmap;
};

#endif