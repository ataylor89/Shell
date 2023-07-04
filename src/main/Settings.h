#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

class Settings
{
public:
    Settings();
    void set_prefix(std::string prefix);
    std::string get_prefix();
private:
    std::string prefix;
};

#endif