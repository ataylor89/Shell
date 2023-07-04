#include "SystemProgram.h"
#include <cstdlib>

SystemProgram::SystemProgram(std::string& cmd, Window* window) : Command(cmd, window) {}

void SystemProgram::exec()
{
    FILE* pipe;
    char buffer[128];
    std::string output;
    TextView* text_view;

    cmd += " 2>&1";

    if ((pipe = popen(cmd.c_str(), "r")) == NULL)
    {
        return;
    }

    while (fgets(buffer, 128, pipe))
    {
        output += buffer;
    }

    pclose(pipe);

    if (!output.empty() && output.back() != '\n') 
    {
        output += "\n";
    }

    text_view = window->get_text_view();
    text_view->append("\n" + output);
    text_view->append_prefix();
}