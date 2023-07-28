#ifndef COMMAND_MAP_H
#define COMMAND_MAP_H

#include "parser/CommandList.h"
#include <map>
#include <string>

using namespace std;

class CommandMap : public map<string, CommandList>
{
public:
    CommandMap();
};

#endif