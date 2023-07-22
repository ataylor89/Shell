#ifndef COMMAND_TYPE_H
#define COMMAND_TYPE_H

enum class CommandType
{
    CD,
    CLEAR,
    EXIT,
    NULL_COMMAND,
    PWD,
    SETPREFIX,
    SYSTEM_PROGRAM,
    USER_PROGRAM
};

#endif