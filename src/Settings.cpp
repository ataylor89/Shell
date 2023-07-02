#include "Settings.h"

Settings::Settings() : prefix("% ") {}

void Settings::set_prefix(std::string prefix)
{
    this->prefix = prefix;
}

std::string Settings::get_prefix()
{
    return prefix;
}