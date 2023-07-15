#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <string>
using namespace std;

vector<string> split(string& str, const string& delimiters);
vector<string> split(string& str, const string& delimiters, int limit);
string trim(string& str);

#endif