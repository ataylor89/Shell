#include "Util.h"
#include "commands/SetPrefix.h"

SetPrefix::SetPrefix(std::string& user_input, Window* window) : Command(user_input, window)
{
    text_view = window->get_text_view();
}

void SetPrefix::exec()
{
    std::vector<std::string> args;

    args = split(user_input, " ", 2);

    if (args.size() == 2)
    {
        settings->set_prefix(args[1] + " ");
    }

    text_view->append("\n");
    text_view->append_prefix();
}