#include "parser/CommandMap.h"

CommandMap::CommandMap() : map<string, CommandType>()
{
    insert({"cat",          CommandType::USER_PROGRAM});
    insert({"cd",           CommandType::CD});
    insert({"clear",        CommandType::CLEAR});
    insert({"exit",         CommandType::EXIT});
    insert({"hexdump",      CommandType::USER_PROGRAM});
    insert({"ls",           CommandType::USER_PROGRAM});
    insert({"pwd",          CommandType::PWD});
    insert({"setprefix",    CommandType::SETPREFIX});
}