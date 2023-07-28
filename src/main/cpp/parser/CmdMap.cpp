#include "parser/CmdMap.h"

CmdMap::CmdMap() : map<string, CmdList>()
{
    insert({"cat",          CmdList::USER_PROGRAM});
    insert({"cd",           CmdList::CD});
    insert({"clear",        CmdList::CLEAR});
    insert({"exit",         CmdList::EXIT});
    insert({"hexdump",      CmdList::USER_PROGRAM});
    insert({"ls",           CmdList::USER_PROGRAM});
    insert({"pwd",          CmdList::PWD});
    insert({"setprefix",    CmdList::SET_PREFIX});
}