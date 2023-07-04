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
    cmd_list["echo"] = 1;
    cmd_list["ls"] = 1;
    cmd_list["cat"] = 1;
    cmd_list["mv"] = 1;
    cmd_list["rm"] = 1;
    cmd_list["cp"] = 1;
    cmd_list["gcc"] = 1;
    cmd_list["g++"] = 1;
    cmd_list["clang++"] = 1;
    cmd_list["java"] = 1;
    cmd_list["python"] = 1;
    cmd_list["git"] = 1;
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
    else if (cmd_list.contains(args[0]))
    {
        return new SystemCommand(cmd, window);
    }
    else
    {
        return NULL;
    }
}