#include "Clear.h"

Clear::Clear(std::string& cmd, Window* window) : Command(cmd, window) {}

void Clear::exec()
{
    TextArea* text_area = window->get_text_area();
    text_area->clear();
}