#ifndef SHELL_H
#define SHELL_H

#include <string>

using namespace std;

class Shell
{
public:
    Shell();
    string exec(string cmd);
private:
    const string output_file;
};

#endif