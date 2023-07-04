#include "SystemCommand.h"
#include <cstdlib>

SystemCommand::SystemCommand(std::string& cmd, Window* window) : Command(cmd, window) {}

void SystemCommand::exec()
{
    FILE* pipe;
    char buffer[128];
    std::string output;
    TextArea* text_area;

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

    text_area = window->get_text_area();
    text_area->append("\n" + output);
    text_area->append_prefix();
}