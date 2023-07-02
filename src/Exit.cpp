#include "Exit.h"

Exit::Exit(const std::string& cmd, Window* window) : Command(cmd, window) {}

void Exit::exec()
{
    auto app = window->get_application();
    app->quit();
}