#include "commands/Command.h"

Command::Command(std::string& user_input, Window* window)
{
    this->user_input = user_input;
    this->window = window;
    settings = window->get_settings();
}

Command::~Command() {}

void Command::preprocess(std::vector<std::string>& args)
{
    if (args.size() > 1 && args[1][0] == '~')
    {
        args[1].erase(0, 1);
        args[1] = settings->get_user_directory() + args[1];
    }
}