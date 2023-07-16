#include "SystemProgram.h"
#include <cstdlib>

SystemProgram::SystemProgram(std::string& user_input, Window* window)
: Command(user_input, window)
{
    text_view = window->get_text_view();
}

void SystemProgram::exec()
{
    FILE* file;
    char buffer[128];
    std::string output;

    user_input += " 2>&1";

    if ((file = popen(user_input.c_str(), "r")) == NULL)
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