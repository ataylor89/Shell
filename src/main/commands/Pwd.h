#ifndef PWD_H
#define PWD_H

#include "gui/Window.h"

class Pwd : public Command
{
public:
    Pwd(std::string& user_input, Window* window);
    void exec();
private:
    TextView* text_view;
};

#endif