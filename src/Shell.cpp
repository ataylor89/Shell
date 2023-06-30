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
        cmd += " > /tmp/shell.txt";
        system(cmd.c_str());
        ostringstream ss;
        ss << ifstream("/tmp/shell.txt").rdbuf();
        string output = ss.str();
        if (!output.empty() && output.back() != '\n')
            output += "\n";
        return output;
}