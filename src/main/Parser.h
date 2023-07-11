#ifndef PARSER_H
#define PARSER_H

#include "Window.h"
#include "ParseTree.h"

class Parser
{
public:
    Parser(Window* window);
    ParseTree* parse(std::string& command);
private:
    Window* window;
    CommandList* command_list;
};

#endif