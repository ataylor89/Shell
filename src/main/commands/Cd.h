#ifndef CD_H
#define CD_H

#include "Window.h"

class Cd : public Command
{
public:
    Cd(std::string& user_input, Window* window);
    void exec();
private:
    void exec(std::string path);
    TextView* text_view;
};

#endif