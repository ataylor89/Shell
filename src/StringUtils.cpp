#include "StringUtils.h"
#include <cstring>

vector<string> StringUtils::split(string& Str, const string& Delim)
{
    vector<string> buffer;
    char *str, *token;
    const char *delim;

    str = strdup(Str.c_str());
    delim = Delim.c_str();

    token = strtok(str, delim);

    while (token)
    {
        buffer.push_back(token);
        token = strtok(NULL, delim);
    }

    return buffer;
}

vector<string> StringUtils::split(string& Str, const string& Delim, int limit)
{
    vector<string> buffer;

    if (limit <= 1)
    {
        buffer.push_back(Str);
        return buffer;
    }

    char *str, *token;
    const char *delim;

    str = strdup(Str.c_str());
    delim = Delim.c_str();

    if ((token = strtok(str, delim)))
    {
        buffer.push_back(token);
        limit--;
    }
    
    while (limit > 1 && (token = strtok(NULL, delim)))
    {
        buffer.push_back(token);
        limit--;
    }

    if ((token = strtok(NULL, "")))
    {
        buffer.push_back(token);
    }
    
    return buffer;
}