#ifndef CD_H
#define CD_H

#include "Window.h"

class Cd : public Command
{
public:
    Cd(std::string& user_input, Window* window);
    void exec();
private:
    TextView* text_view;
};

#endif