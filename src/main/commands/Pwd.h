#ifndef PWD_H
#define PWD_H

#include "Window.h"

class Pwd : public Command
{
public:
    Pwd(std::string& user_input, Window* window);
    void exec();
private:
    TextView* text_view;
};

#endif