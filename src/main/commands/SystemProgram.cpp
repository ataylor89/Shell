#include "commands/SystemProgram.h"
#include <cstdlib>

SystemProgram::SystemProgram(string& cmd, vector<string>& args, Window* window)
: Command(cmd, args, window)
{
    text_view = window->get_text_view();
}

void SystemProgram::exec()
{
    FILE* file;
    char buffer[128];
    string output;

    cmd += " 2>&1";

    if ((file = popen(cmd.c_str(), "r")) == NULL)
    {
        return;
    }

    while (fgets(buffer, 128, file))
    {
        output += buffer;
    }

    pclose(file);

    if (!output.empty() && output.back() != '\n') 
    {
        output += "\n";
    }

    text_view->append("\n" + output);
    text_view->append_prefix();
}