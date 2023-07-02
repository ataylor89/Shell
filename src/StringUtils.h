#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <vector>
#include <string>

namespace StringUtils
{
    std::vector<std::string> split(const std::string& str, char delim);
};

#endif