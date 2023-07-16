#include "CommandList.h"

CommandList::CommandList() : map<string, CommandType>()
{
    insert({"clear",        CommandType::CLEAR});
    insert({"setprefix",    CommandType::SETPREFIX});
    insert({"exit",         CommandType::EXIT});
    insert({"cat",          CommandType::USER_PROGRAM});
    insert({"ls",           CommandType::USER_PROGRAM});
    insert({"hexdump",      CommandType::USER_PROGRAM});
}