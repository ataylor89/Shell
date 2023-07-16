#include "Parser.h"
#include "Clear.h"
#include "Exit.h"
#include "NullCommand.h"
#include "SetPrefix.h"
#include "SystemProgram.h"
#include "UserProgram.h"
#include "Util.h"

Parser::Parser(Window* window)
{
    this->window = window;
    this->command_list = new CommandList;
}

Command* Parser::parse(std::string& user_input)
{
    std::vector<std::string> args;

    trim(user_input);
    args = split(user_input, " ");

    if (args.empty())
    {
        return new NullCommand(user_input, window);
    }

    else if (args[0].length() > 1 && args[0][0] == '*')
    {
        user_input.erase(0, 1);
        return new SystemProgram(user_input, window);
    }

    else if (!command_list->contains(args[0]))
    {
        return new NullCommand(user_input, window, "Command not found.");
    }

    else
    {
        CommandType command_type = (*command_list)[args[0]];
        switch (command_type)
        {
            case CommandType::CLEAR:
                return new Clear(user_input, window);
            case CommandType::EXIT:
                return new Exit(user_input, window);
            case CommandType::SETPREFIX:
                return new SetPrefix(user_input, window);
            case CommandType::USER_PROGRAM:
                return new UserProgram(user_input, window);
            default:
                return new NullCommand(user_input, window);
        }
    }
}