#include "Shell.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

Shell::Shell() {}

string Shell::exec(string cmd)
{
    if (cmd.find_first_not_of(' ') == string::npos)
        return "";
    cmd += " 2>&1";
    FILE* pipe = popen(cmd.c_str(), "r");
    string output;
    char buffer[128];
    while (fgets(buffer, 128, pipe))
        output += buffer;
    if (!output.empty() && output.back() != '\n')
        output += "\n";
    return output;
}