#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <vector>
#include <string>

using namespace std;

namespace StringUtils
{
    vector<string> split(const string& str, const string& delim);
    vector<string> split(const string& str, const string& delim, int limit);
};

#endif