#include "Parser.h"
#include "Clear.h"
#include "Command.h"
#include "StringUtils.h"

Parser::Parser(Window* window) 
{
    this->window = window;
}

Command* Parser::parse(const std::string cmd)
{
    std::vector<std::string> args = StringUtils::split(cmd, ' ');
    if (args.empty())
    {
        return NULL;
    }
    else if (args[0] == "clear")
    {
        return new Clear(cmd, window);
    }
    else
    {
        return new Command(cmd, window);
    }
}