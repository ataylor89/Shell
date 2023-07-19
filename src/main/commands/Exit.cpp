#include "commands/Exit.h"

Exit::Exit(string& cmd, vector<string>& args, Window* window) : Command(cmd, args, window) {}

void Exit::exec()
{
    auto app = window->get_application();
    app->quit();
}