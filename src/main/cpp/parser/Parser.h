#ifndef PARSER_H
#define PARSER_H

#include "gui/Window.h"
#include "commands/Command.h"
#include "parser/CommandMap.h"

class Parser
{
public:
    Parser(Window* window);
    Command* parse(string& cmd);
private:
    void replace_tilde(vector<string>& args);
    Window* window;
    Settings* settings;
    CommandMap* command_map;
};

#endif