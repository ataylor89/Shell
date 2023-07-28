#include "parser/CommandMap.h"

CommandMap::CommandMap() : map<string, CommandList>()
{
    insert({"cat",          CommandList::USER_PROGRAM});
    insert({"cd",           CommandList::CD});
    insert({"clear",        CommandList::CLEAR});
    insert({"exit",         CommandList::EXIT});
    insert({"hexdump",      CommandList::USER_PROGRAM});
    insert({"ls",           CommandList::USER_PROGRAM});
    insert({"pwd",          CommandList::PWD});
    insert({"setprefix",    CommandList::SETPREFIX});
}