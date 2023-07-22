#ifndef NULL_COMMAND_H
#define NULL_COMMAND_H

#include "gui/Window.h"

class NullCommand : public Command
{
public:
    NullCommand(string& cmd, vector<string>& args, Window* window);
    NullCommand(string& cmd, vector<string>& args, Window* window, std::string error_message);
    void exec();
private:
    TextView* text_view;
    std::string error_message;
};

#endif