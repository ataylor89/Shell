#ifndef CAT_H
#define CAT_H

#include "Window.h"

class Cat : public Command
{
public:
    Cat(std::string& user_input, Window* window);
    void exec();
private:
    void exec(const char* filename);
    TextView* text_view;
};

#endif