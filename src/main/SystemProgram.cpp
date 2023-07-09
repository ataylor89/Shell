#include "SystemProgram.h"
#include <cstdlib>

SystemProgram::SystemProgram(string& cmd, Window* window) : Command(cmd, window) {}

void SystemProgram::exec()
{
    FILE* stream;
    char buffer[128];
    string output;
    TextView* text_view;

    cmd += " 2>&1";

    if ((stream = popen(cmd.c_str(), "r")) == NULL)
    {
        return;
    }

    while (fgets(buffer, 128, stream))
    {
        output += buffer;
    }

    pclose(stream);

    if (!output.empty() && output.back() != '\n') 
    {
        output += "\n";
    }

    text_view = window->get_text_view();
    text_view->append("\n" + output);
    text_view->append_prefix();
}