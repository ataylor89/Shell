#include "SetPrefix.h"
#include "StringUtils.h"

SetPrefix::SetPrefix(std::string& cmd, Window* window) : Command(cmd, window) {}

void SetPrefix::exec()
{
    std::vector<std::string> args;
    Settings* settings;
    TextView* text_view;

    args = split(cmd, " ", 2);

    if (args.size() == 2)
    {
        settings = window->get_settings();
        settings->set_prefix(args[1] + " ");
    }

    text_view = window->get_text_view();
    text_view->append("\n");
    text_view->append_prefix();
}