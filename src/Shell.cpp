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
    string output;
    char buffer[128];
    FILE* pipe = popen(cmd.c_str(), "r");
    while (fgets(buffer, 128, pipe))
        output += buffer;
    pclose(pipe);
    if (!output.empty() && output.back() != '\n')
        output += "\n";
    return output;
}