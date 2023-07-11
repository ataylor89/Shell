#ifndef COMMAND_LIST_H
#define COMMAND_LIST_H

#include <string>
#include <map>

#include "CommandType.h"

using namespace std;

class CommandList : public map<string, CommandType>
{
public:
    CommandList();
};

#endif