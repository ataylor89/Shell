#include "Shell.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

Shell::Shell() {}

void Shell::exec(std::string command)
{
    if (command.find_first_not_of(' ') == std::string::npos)
        return;

    Glib::RefPtr<Gtk::TextBuffer> buffer = text_area->get_buffer();

    if (command == "clear")
    {
        std::string prefix = text_area->get_prefix();
        buffer->set_text(prefix);
    }
    else
    {
        command += " 2>&1";
        std::string output;
        char tmp[128];
        FILE* pipe;
        if ((pipe = popen(command.c_str(), "r")) == NULL)
            return;
        while (fgets(tmp, 128, pipe))
            output += tmp;
        pclose(pipe);
        if (!output.empty() && output.back() != '\n')
            output += "\n";
        std::string prefix = text_area->get_prefix();
        buffer->insert_at_cursor("\n" + output + prefix);
    }
}

void Shell::set_text_area(TextArea* text_area)
{
    this->text_area = text_area;
}

TextArea* Shell::get_text_area()
{
    return text_area;
}