#include "commands/Exit.h"

Exit::Exit(std::string& user_input, Window* window) : Command(user_input, window) {}

void Exit::exec()
{
    auto app = window->get_application();
    app->quit();
}