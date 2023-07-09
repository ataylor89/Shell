#ifndef SET_PREFIX_H
#define SET_PREFIX_H

#include "Command.h"
using namespace std;

class SetPrefix : public Command
{
public:
    SetPrefix(string& cmd, Window* window);
    void exec();
};

#endif