#ifndef SHELL_H
#define SHELL_H

#include "Window.h"

class Shell
{
public:
    Shell();
    void exec(std::string command);
    void set_text_area(TextArea* text_area);
    TextArea* get_text_area();
private:
    TextArea* text_area;
};

#endif