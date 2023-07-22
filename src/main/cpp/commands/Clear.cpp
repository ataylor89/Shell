#include "commands/Clear.h"

Clear::Clear(string& cmd, vector<string>& args, Window* window) : Command(cmd, args, window)
{
    text_view = window->get_text_view();
}

void Clear::exec()
{
    text_view->clear();

    delete this;
}