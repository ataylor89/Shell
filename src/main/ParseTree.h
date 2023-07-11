#ifndef PARSE_TREE_H
#define PARSE_TREE_H

#include "Window.h"

struct ParseTree
{
    StatusCode status_code;
    Command* cmd;
    ParseTree();
    ~ParseTree();
};

#endif