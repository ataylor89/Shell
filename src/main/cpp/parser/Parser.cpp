#include "parser/Parser.h"
#include "util/StringUtils.h"
#include "commands/Cd.h"
#include "commands/Clear.h"
#include "commands/Exit.h"
#include "commands/NullCommand.h"
#include "commands/Pwd.h"
#include "commands/SetPrefix.h"
#include "commands/SystemProgram.h"
#include "commands/UserProgram.h"

Parser::Parser(Window* window)
{
    this->window = window;
    settings = window->get_settings();
    command_map = new CommandMap;
}

Command* Parser::parse(string& cmd)
{
    vector<string> args;

    trim(cmd);
    args = split(cmd, " ");

    if (args.empty())
    {
        return new NullCommand(cmd, args, window);
    }

    else if (args[0].length() > 1 && args[0][0] == '*')
    {
        cmd.erase(0, 1);
        return new SystemProgram(cmd, args, window);
    }

    else if (!command_map->contains(args[0]))
    {
        return new NullCommand(cmd, args, window, "Command not found.");
    }

    else
    {
        replace_tilde(args);

        CommandType command_type = (*command_map)[args[0]];
        switch (command_type)
        {
            case CommandType::CD:
                return new Cd(cmd, args, window);
            case CommandType::CLEAR:
                return new Clear(cmd, args, window);
            case CommandType::EXIT:
                return new Exit(cmd, args, window);
            case CommandType::PWD:
                return new Pwd(cmd, args, window);
            case CommandType::SETPREFIX:
                return new SetPrefix(cmd, args, window);
            case CommandType::USER_PROGRAM:
                return new UserProgram(cmd, args, window);
            default:
                return new NullCommand(cmd, args, window);
        }
    }
}

void Parser::replace_tilde(vector<string>& args)
{
    if (args.size() > 1 && args[1][0] == '~')
    {
        args[1].erase(0, 1);
        args[1] = settings->get_user_directory() + args[1];
    }
}