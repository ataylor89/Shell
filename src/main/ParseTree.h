#ifndef PARSE_TREE_H
#define PARSE_TREE_H

#include "Command.h"
#include "StatusCode.h"

struct ParseTree
{
    StatusCode status_code;
    Command* cmd;
    ParseTree();
    ~ParseTree();
};

#endif