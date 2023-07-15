#include "SystemProgram.h"
#include <cstdlib>

SystemProgram::SystemProgram(std::string& user_input, Window* window) : Command(user_input, window) {}

void SystemProgram::exec()
{
    FILE* stream;
    char buffer[128];
    std::string output;
    TextView* text_view;

    user_input += " 2>&1";

    if ((stream = popen(user_input.c_str(), "r")) == NULL)
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