#include "ParseTree.h"

ParseTree::ParseTree()
{
    cmd = NULL;
}

ParseTree::~ParseTree()
{
    if (cmd != NULL)
    {
        delete cmd;
    }
}