#include "Command.h"

Command::Command(std::string& user_input, Window* window)
{
    this->user_input = user_input;
    this->window = window;
}

Command::~Command() {}