#include "Settings.h"

Settings::Settings() {}

Settings::Settings(std::string prefix, std::string program_directory)
{
    this->prefix = prefix;
    this->program_directory = program_directory;
}

void Settings::set_prefix(std::string prefix)
{
    this->prefix = prefix;
}

std::string Settings::get_prefix()
{
    return prefix;
}

void Settings::set_program_directory(std::string program_directory)
{
    this->program_directory = program_directory;
}

std::string Settings::get_program_directory()
{
    return program_directory;
}