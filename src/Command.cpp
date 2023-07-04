#include "Command.h"

Command::Command(std::string& cmd, Window* window)
{
    this->cmd = cmd;
    this->window = window;
}

Command::~Command() {}