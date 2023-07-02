#include "Parser.h"
#include "Command.h"
#include "Clear.h"
#include "SetPrefix.h"
#include "Exit.h"
#include "StringUtils.h"

Parser::Parser(Window* window) 
{
    this->window = window;
}

Command* Parser::parse(std::string cmd)
{
    std::vector<std::string> args = StringUtils::split(cmd, " ");
    if (args.empty())
    {
        return NULL;
    }
    else if (args[0] == "clear")
    {
        return new Clear(cmd, window);
    }
    else if (args[0] == "setprefix")
    {
        return new SetPrefix(cmd, window);
    }
    else if (args[0] == "exit")
    {
        return new Exit(cmd, window);
    }
    else
    {
        return new Command(cmd, window);
    }
}