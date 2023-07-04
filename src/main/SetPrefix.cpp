#include "SetPrefix.h"
#include "StringUtils.h"

SetPrefix::SetPrefix(std::string& cmd, Window* window) : Command(cmd, window) {}

void SetPrefix::exec()
{
    std::vector<std::string> args;
    Settings* settings;
    TextArea* text_area;

    args = StringUtils::split(cmd, " ", 2);

    if (args.size() == 2)
    {
        settings = window->get_settings();
        settings->set_prefix(args[1] + " ");
    }

    text_area = window->get_text_area();
    text_area->append("\n");
    text_area->append_prefix();
}