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

    else if (!cmdmap.contains(args[0]))
    {
        return new NullCommand(cmd, args, window, "Command not found.");
    }

    else
    {
        replace_tilde(args);

        switch (cmdmap[args[0]])
        {
            case CmdList::CD:
                return new Cd(cmd, args, window);
            case CmdList::CLEAR:
                return new Clear(cmd, args, window);
            case CmdList::EXIT:
                return new Exit(cmd, args, window);
            case CmdList::PWD:
                return new Pwd(cmd, args, window);
            case CmdList::SET_PREFIX:
                return new SetPrefix(cmd, args, window);
            case CmdList::USER_PROGRAM:
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