#include "Pwd.h"
#include "Util.h"
#include <filesystem>

Pwd::Pwd(std::string& user_input, Window* window) : Command(user_input, window)
{
    text_view = window->get_text_view();
}

void Pwd::exec()
{
    std::vector<std::string> args;

    args = split(user_input, " ");

    if (args.size() == 1)
    {
        text_view->append("\n" + std::filesystem::current_path().string());
    }

    text_view->append("\n");
    text_view->append_prefix();
}