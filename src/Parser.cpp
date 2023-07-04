#include "Parser.h"
#include "Command.h"
#include "Clear.h"
#include "SetPrefix.h"
#include "Exit.h"
#include "SystemCommand.h"
#include "StringUtils.h"

Parser::Parser(Window* window) 
{
    this->window = window;
    dict["echo"] = 1;
    dict["ls"] = 1;
    dict["cat"] = 1;
    dict["mv"] = 1;
    dict["rm"] = 1;
    dict["cp"] = 1;
    dict["gcc"] = 1;
    dict["g++"] = 1;
    dict["clang++"] = 1;
    dict["java"] = 1;
    dict["python"] = 1;
    dict["git"] = 1;
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
    else if (dict.contains(args[0]))
    {
        return new SystemCommand(cmd, window);
    }
    else
    {
        return NULL;
    }
}