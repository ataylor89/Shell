#include "CommandList.h"

CommandList::CommandList() : map<string, CommandType>()
{
    insert({"clear",        CommandType::CLEAR});
    insert({"setprefix",    CommandType::SETPREFIX});
    insert({"exit",         CommandType::EXIT});
    insert({"cat",          CommandType::CAT});
    insert({"hexdump",      CommandType::HEXDUMP});
}