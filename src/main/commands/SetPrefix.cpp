#include "SetPrefix.h"
#include "Util.h"

SetPrefix::SetPrefix(std::string& user_input, Window* window) : Command(user_input, window) {}

void SetPrefix::exec()
{
    std::vector<std::string> args;
    Settings* settings;
    TextView* text_view;

    args = split(user_input, " ", 2);

    if (args.size() == 2)
    {
        settings = window->get_settings();
        settings->set_prefix(args[1] + " ");
    }

    text_view = window->get_text_view();
    text_view->append("\n");
    text_view->append_prefix();
}