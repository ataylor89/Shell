#include "StringUtils.h"
#include <cstring>

vector<string> StringUtils::split(const string& Str, const string& Delim)
{
    vector<string> vec;
    char *str, *token;
    const char *delim;

    str = strdup(Str.c_str());
    delim = Delim.c_str();

    token = strtok(str, delim);

    while (token)
    {
        vec.push_back(token);
        token = strtok(NULL, delim);
    }

    return vec;
}

vector<string> StringUtils::split(const string& Str, const string& Delim, int limit)
{
    vector<string> vec;

    if (limit <= 0)
    {
        return vec;
    }

    char *str, *token;
    const char *delim;

    str = strdup(Str.c_str());
    delim = Delim.c_str();

    if (limit > 1 && (token = strtok(str, delim)))
    {
        vec.push_back(token);
        limit--;
    }
    
    while (limit > 1 && (token = strtok(NULL, delim)))
    {
        vec.push_back(token);
        limit--;
    }

    if (limit == 1 && (token = strtok(NULL, "")))
    {
        vec.push_back(token);
    }
    
    return vec;
}