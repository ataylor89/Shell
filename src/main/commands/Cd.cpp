#include "Util.h"
#include "commands/Cd.h"
#include <filesystem>

Cd::Cd(string& cmd, vector<string>& args, Window* window) : Command(cmd, args, window)
{
    text_view = window->get_text_view();
}

void Cd::exec()
{
    if (args.size() == 2)
    {
        if (filesystem::is_directory(args[1]))
        {
            if (args[1][0] == '/')
            {
                filesystem::current_path(args[1]);
            }

            else
            {
                filesystem::current_path(filesystem::current_path() /= args[1]);
            }
        }

        else
        {
            text_view->append("\nTerminal: The given path is not a directory.");
        }
    }

    text_view->append("\n");
    text_view->append_prefix();
}