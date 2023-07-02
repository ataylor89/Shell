#include "Command.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

Command::Command(const std::string& cmd, Window* window)
{
    this->cmd = cmd;
    this->window = window;
}

void Command::exec()
{
    std::string process, output, prefix;
    char buffer[128];
    FILE* pipe;
    TextArea* text_area;

    process = cmd + " 2>&1";

    if ((pipe = popen(process.c_str(), "r")) == NULL)
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