#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

class Settings
{
public:
    Settings();
    void load();
    void set_prefix(std::string prefix);
    std::string get_prefix();
    std::string get_program_directory();
    int get_user_id();
    int get_group_id();
    std::string get_username();
    std::string get_groupname();
    std::string get_user_directory();
private:
    std::string prefix;
    std::string program_directory;
    int user_id;
    int group_id;
    std::string username;
    std::string groupname;
    std::string user_directory;
};

#endif