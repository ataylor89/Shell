#include "Parser.h"
#include "Command.h"
#include "Clear.h"
#include "SetPrefix.h"
#include "Exit.h"
#include "SystemProgram.h"
#include "StringUtils.h"

Parser::Parser(Window* window) 
{
    this->window = window;
}

Command* Parser::parse(std::string cmd)
{
    trim(cmd);

    vector<string> args = split(cmd, " ");

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
    else if (args[0][0] == '*' && args[0].length() > 1)
    {
        cmd.erase(0, 1);
        return new SystemProgram(cmd, window);
    }
    else
    {
        return NULL;
    }
}