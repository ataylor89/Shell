#ifndef PARSER_H
#define PARSER_H

#include "gui/Window.h"
#include "commands/Command.h"
#include "parser/CommandList.h"

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