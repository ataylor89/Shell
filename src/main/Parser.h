#ifndef PARSER_H
#define PARSER_H

#include "Window.h"
#include "Command.h"
#include "CommandList.h"

class Parser
{
public:
    Parser(Window* window);
    Command* parse(std::string& user_input);
private:
    Window* window;
    CommandList* command_list;
};

#endif