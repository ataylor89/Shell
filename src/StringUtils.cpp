#include "StringUtils.h"
#include <cstring>

vector<string> StringUtils::split(const string& _str, const string& _delim)
{
    vector<string> vec;
    char *str, *token;
    const char *delim;

    str = strdup(_str.c_str());
    delim = _delim.c_str();

    token = strtok(str, delim);

    while (token)
    {
        vec.push_back(string(token));
        token = strtok(NULL, delim);
    }

    return vec;
}

vector<string> StringUtils::split(const string& _str, const string& _delim, int limit)
{
    vector<string> vec;
    char *str, *token;
    const char *delim;

    str = strdup(_str.c_str());
    delim = _delim.c_str();

    token = strtok(str, delim);

    vec.push_back(token);
    limit--;
    
    while (limit > 1 && (token = strtok(NULL, delim)))
    {
        vec.push_back(string(token));
        limit--;
    }

    token = strtok(NULL, "");

    vec.push_back(string(token));
    return vec;
}