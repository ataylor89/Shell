#ifndef CD_H
#define CD_H

#include "gui/Window.h"

class Cd : public Command
{
public:
    Cd(std::string& user_input, Window* window);
    void exec();
private:
    void preprocess(std::string& path);
    TextView* text_view;
    Settings* settings;
};

#endif