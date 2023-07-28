#ifndef COMMAND_LIST_H
#define COMMAND_LIST_H

#include "parser/CommandType.h"
#include <map>
#include <string>

using namespace std;

class CommandMap : public map<string, CommandType>
{
public:
    CommandMap();
};

#endif