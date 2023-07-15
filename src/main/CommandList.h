#ifndef COMMAND_LIST_H
#define COMMAND_LIST_H

#include "CommandType.h"
#include <map>
#include <string>
using namespace std;

class CommandList : public map<string, CommandType>
{
public:
    CommandList();
};

#endif