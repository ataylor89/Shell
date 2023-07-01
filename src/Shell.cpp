#include "Shell.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

Shell::Shell() 
: output_file("/tmp/shell.txt") 
{
    
}

string Shell::exec(string cmd)
{
        if (cmd.find_first_not_of(' ') == string::npos)
            return "";
        cmd += " &> " + output_file;
        system(cmd.c_str());
        ostringstream ss;
        ss << ifstream(output_file).rdbuf();
        string output = ss.str();
        if (!output.empty() && output.back() != '\n')
            output += "\n";
        return output;
}