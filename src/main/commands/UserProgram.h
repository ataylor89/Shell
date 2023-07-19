#ifndef USER_PROGRAM_H
#define USER_PROGRAM_H

#include "gui/Window.h"

class UserProgram : public Command
{
public:
    UserProgram(std::string& user_input, Window* window);
    void exec();
private:
    void exec(const char* path, char** argv);
    TextView* text_view;
    Settings* settings;
};

#endif