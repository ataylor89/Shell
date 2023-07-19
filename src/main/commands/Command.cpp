#include "commands/Command.h"

Command::Command(string& cmd, vector<string>& args, Window* window)
{
    this->cmd = cmd;
    this->args = args;
    this->window = window;
}

Command::~Command() {}