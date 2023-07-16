#include "Cd.h"
#include "Util.h"
#include <filesystem>

Cd::Cd(std::string& user_input, Window* window) : Command(user_input, window)
{
    text_view = window->get_text_view();
}

void Cd::exec()
{
    std::vector<std::string> args;
    std::filesystem::path path;

    args = split(user_input, " ", 2);

    if (args.size() == 2)
    {
        exec(args[1]);
    }

    text_view->append("\n");
    text_view->append_prefix();
}

void Cd::exec(std::string path)
{
    std::filesystem::path current_directory;
    current_directory = std::filesystem::current_path();

    if (std::filesystem::is_directory(path))
    {
        if (path[0] == '/')
        {
            std::filesystem::current_path(path);
        }

        else
        {
            std::filesystem::current_path(current_directory /= path);
        }
    }

    else
    {
        text_view->append("\nTerminal: The given path is not a directory.");
    }
}