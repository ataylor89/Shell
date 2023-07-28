#ifndef COMMAND_MAP_H
#define COMMAND_MAP_H

#include "parser/CmdList.h"
#include <map>
#include <string>

using namespace std;

class CmdMap : public map<string, CmdList>
{
public:
    CmdMap();
};

#endif