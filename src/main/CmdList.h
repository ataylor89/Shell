#ifndef CMD_LIST_H
#define CMD_LIST_H

#include "CommandType.h"
#include <map>
#include <string>

using namespace std;

class CmdList : public map<string, CommandType>
{
public:
    CmdList();
};

#endif