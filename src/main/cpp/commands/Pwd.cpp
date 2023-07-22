#include "commands/Pwd.h"
#include <filesystem>

Pwd::Pwd(string& cmd, vector<string>& args, Window* window) : Command(cmd, args, window)
{
    text_view = window->get_text_view();
}

void Pwd::exec()
{
    if (args.size() == 1)
    {
        text_view->append("\n" + filesystem::current_path().string());
    }

    text_view->append("\n");
    text_view->append_prefix();

    delete this;
}