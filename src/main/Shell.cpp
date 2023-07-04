#include "Shell.h"

Shell::Shell(Window* window) 
{
    this->window = window;
}

void Shell::exec(std::string command)
{
    Parser* parser;
    Command* cmd;
    TextView* text_view;

    parser = window->get_parser();
    cmd = parser->parse(command);
    
    if (cmd == NULL)
    {
        text_view = window->get_text_view();
        text_view->append("\n");
        text_view->append_prefix();
    }
    else
    {
        cmd->exec();
        delete cmd;
    }
}