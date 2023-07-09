#ifndef PARSER_H
#define PARSER_H

#include "Window.h"
#include "Command.h"
#include <map>

using namespace std;

class Parser
{
public:
    Parser(Window* window);
    Command* parse(string command);
private:
    Window* window;
    map<string, int> cmd_list;

};

#endif