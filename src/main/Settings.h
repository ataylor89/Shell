#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

using namespace std;

class Settings
{
public:
    Settings();
    void load();
    void set_prefix(string prefix);
    string get_prefix();
    string get_program_directory();
    int get_user_id();
    int get_group_id();
    string get_username();
    string get_groupname();
    string get_user_directory();
private:
    string prefix;
    string program_directory;
    int user_id;
    int group_id;
    string username;
    string groupname;
    string user_directory;
};

#endif