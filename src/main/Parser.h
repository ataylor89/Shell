#ifndef PARSER_H
#define PARSER_H

#include "Window.h"

class Parser
{
public:
    Parser(Window* window);
    ParseTree* parse(std::string& command);
    CommandList* get_command_list();
private:
    Window* window;
    CommandList* command_list;
};

#endif