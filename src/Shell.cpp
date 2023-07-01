#include "Shell.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

Shell::Shell() {}

string Shell::exec(string cmd)
{
    string output;
    char buffer[128];
    if (cmd.find_first_not_of(' ') == string::npos)
        return "";
    cmd += " 2>&1";
    FILE* pipe = popen(cmd.c_str(), "r");
    while (fgets(buffer, 128, pipe))
        output += buffer;
    pclose(pipe);
    if (!output.empty() && output.back() != '\n')
        output += "\n";
    return output;
}