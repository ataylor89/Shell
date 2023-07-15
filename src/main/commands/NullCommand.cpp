#include "NullCommand.h"

NullCommand::NullCommand(std::string& str, Window* window) 
: Command(str, window)
{
    this->text_view = window->get_text_view();
}

NullCommand::NullCommand(std::string& str, Window* window, std::string error_message)
: Command(str, window)
{
    this->text_view = window->get_text_view();
    this->error_message = error_message;
}

void NullCommand::exec()
{
    if (error_message.empty())
    {
        text_view->append("\n");
        text_view->append_prefix();
    }
    else
    {
        text_view->append("\n" + error_message + "\n");
        text_view->append_prefix();
    }
}