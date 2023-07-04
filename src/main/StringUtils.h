#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <vector>
#include <string>

using namespace std;

namespace StringUtils
{
    vector<string> split(string& str, const string& delimiters);
    vector<string> split(string& str, const string& delimiters, int limit);
};

#endif