#include "StringUtils.h"
#include <cstring>

vector<string> StringUtils::split(string& Str, const string& Delimiters)
{
    vector<string> buffer;
    char *str, *token;
    const char *delimiters;

    str = strdup(Str.c_str());
    delimiters = Delimiters.c_str();

    token = strtok(str, delimiters);

    while (token)
    {
        buffer.push_back(token);
        token = strtok(NULL, delimiters);
    }

    return buffer;
}

vector<string> StringUtils::split(string& Str, const string& Delimiters, int limit)
{
    vector<string> buffer;

    if (limit <= 1)
    {
        buffer.push_back(Str);
        return buffer;
    }

    char *str, *token;
    const char *delimiters;

    str = strdup(Str.c_str());
    delimiters = Delimiters.c_str();

    if ((token = strtok(str, delimiters)))
    {
        buffer.push_back(token);
        limit--;
    }
    
    while (limit > 1 && (token = strtok(NULL, delimiters)))
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