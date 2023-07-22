#include "commands/SetPrefix.h"

SetPrefix::SetPrefix(string& cmd, vector<string>& args, Window* window) : Command(cmd, args, window)
{
    text_view = window->get_text_view();
    settings = window->get_settings();
}

void SetPrefix::exec()
{
    if (args.size() == 2)
    {
        settings->set_prefix(args[1] + " ");
    }

    text_view->append("\n");
    text_view->append_prefix();

    delete this;
}