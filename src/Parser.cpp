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
    cmd_map["echo"] = 1;
    cmd_map["ls"] = 1;
    cmd_map["cat"] = 1;
    cmd_map["mv"] = 1;
    cmd_map["rm"] = 1;
    cmd_map["cp"] = 1;
    cmd_map["gcc"] = 1;
    cmd_map["g++"] = 1;
    cmd_map["clang++"] = 1;
    cmd_map["java"] = 1;
    cmd_map["python"] = 1;
    cmd_map["git"] = 1;
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
    else if (cmd_map.contains(args[0]))
    {
        return new SystemCommand(cmd, window);
    }
    else
    {
        return NULL;
    }
}