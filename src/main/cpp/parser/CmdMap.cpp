#include "parser/CmdMap.h"

CmdMap::CmdMap() : map<string, CmdList>()
{
    insert({"cat",          CmdList::CAT});
    insert({"cd",           CmdList::CD});
    insert({"clear",        CmdList::CLEAR});
    insert({"exit",         CmdList::EXIT});
    insert({"hexdump",      CmdList::HEXDUMP});
    insert({"ls",           CmdList::LS});
    insert({"pwd",          CmdList::PWD});
    insert({"setprefix",    CmdList::SET_PREFIX});
}