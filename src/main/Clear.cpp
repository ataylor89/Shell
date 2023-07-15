#include "Clear.h"

Clear::Clear(std::string& user_input, Window* window) : Command(user_input, window) {}

void Clear::exec()
{
    TextView* text_view = window->get_text_view();
    text_view->clear();
}