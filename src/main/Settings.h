#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

class Settings
{
public:
    Settings();
    Settings(std::string prefix, std::string program_directory);
    void set_prefix(std::string prefix);
    std::string get_prefix();
    void set_program_directory(std::string program_directory);
    std::string get_program_directory();
private:
    std::string prefix;
    std::string program_directory;
};

#endif