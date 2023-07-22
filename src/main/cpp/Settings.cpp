#include "Settings.h"
#include <filesystem>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

Settings::Settings()
: prefix("% "), program_directory(filesystem::current_path().string() + "/bin")
{

}

void Settings::load()
{
    struct passwd* pw;
    struct group* gr;

    user_id = getuid();

    if ((pw = getpwuid(user_id)) == NULL)
    {
        fprintf(stderr, "Error looking up user ID.\n");
        return;
    }

    username = pw->pw_name;
    user_directory = pw->pw_dir;
    group_id = pw->pw_gid;

    if ((gr = getgrgid(group_id)) == NULL)
    {
        fprintf(stderr, "Error looking up group ID.\n");
        return;
    }

    groupname = gr->gr_name;
}

void Settings::set_prefix(string prefix)
{
    this->prefix = prefix;
}

string Settings::get_prefix()
{
    return prefix;
}

string Settings::get_program_directory()
{
    return program_directory;
}

int Settings::get_user_id()
{
    return user_id;
}

int Settings::get_group_id()
{
    return group_id;
}

string Settings::get_username()
{
    return username;
}

string Settings::get_groupname()
{
    return groupname;
}

string Settings::get_user_directory()
{
    return user_directory;
}