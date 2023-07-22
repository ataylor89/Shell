#ifndef USER_PROGRAM_H
#define USER_PROGRAM_H

#include "gui/Window.h"

class UserProgram : public Command
{
public:
    UserProgram(string& cmd, vector<string>& args, Window* window);
    void exec();
private:
    void exec(const char* path, char** argv);
    TextView* text_view;
    Settings* settings;
};

#endif