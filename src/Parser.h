#ifndef PARSER_H
#define PARSER_H

#include "Window.h"
#include "Command.h"

class Parser
{
public:
    Parser(Window* window);
    Command* parse(std::string command);
private:
    Window* window;
};

#endif