#include "Parser.h"
#include "Command.h"
#include "Clear.h"
#include "SetPrefix.h"
#include "Cat.h"
#include "Hexdump.h"
#include "Exit.h"
#include "SystemProgram.h"
#include "StringUtils.h"

Parser::Parser(Window* window)
{
    this->window = window;
    this->cmd_list = window->get_cmd_list();
}

ParseTree* Parser::parse(std::string& cmd)
{
    ParseTree* parse_tree;
    std::vector<std::string> args;

    parse_tree = new ParseTree;

    trim(cmd);
    args = split(cmd, " ");

    if (args.empty())
    {
        parse_tree->status_code = StatusCode::BLANK_LINE;
    }
    else if (args[0].length() > 1 && args[0][0] == '*')
    {
        cmd.erase(0, 1);
        parse_tree->cmd = new SystemProgram(cmd, window);
        parse_tree->status_code = StatusCode::OK;
    }
    else if (!cmd_list->contains(args[0]))
    {
        parse_tree->status_code = StatusCode::COMMAND_NOT_FOUND;
    }
    else
    {
        CommandType cmd_type = (*cmd_list)[args[0]];
        switch (cmd_type)
        {
            case CommandType::CLEAR:
                parse_tree->cmd = new Clear(cmd, window);
                break;
            case CommandType::SETPREFIX:
                parse_tree->cmd = new SetPrefix(cmd, window);
                break;
            case CommandType::EXIT:
                parse_tree->cmd = new Exit(cmd, window);
                break;
            case CommandType::CAT:
                parse_tree->cmd = new Cat(cmd, window);
                break;
            case CommandType::HEXDUMP:
                parse_tree->cmd = new Hexdump(cmd, window);
                break;
        }
        parse_tree->status_code = StatusCode::OK;
    }

    return parse_tree;
}