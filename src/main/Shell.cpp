#include "Shell.h"

Shell::Shell(Window* window) 
{
    this->window = window;
    this->text_view = window->get_text_view();
    this->parser = new Parser(window);
}

void Shell::exec(std::string command)
{
    ParseTree* parse_tree;
    Command* cmd;

    parse_tree = parser->parse(command);

    switch (parse_tree->status_code)
    {
        case StatusCode::OK:
            cmd = parse_tree->cmd;
            cmd->exec();
            break;
        case StatusCode::COMMAND_NOT_FOUND:
            text_view->append("\nCommand not found.\n");
            text_view->append_prefix();
            break;
        default:
            text_view->append("\n");
            text_view->append_prefix();
            break;
    }

    delete parse_tree;
}