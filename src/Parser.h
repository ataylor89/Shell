#ifndef PARSER_H
#define PARSER_H

#include "Window.h"
#include "Command.h"
#include <map>

class Parser
{
public:
    Parser(Window* window);
    Command* parse(std::string command);
private:
    Window* window;
    std::map<std::string, int> cmd_map;

};

#endif