#ifndef WINDOW_H
#define WINDOW_H

class Window;
class Settings;
class TextView;
class CmdList;
class Shell;
class Parser;
struct ParseTree;
class Command;

#include <gtkmm.h>
#include "Settings.h"
#include "TextView.h"
#include "Shell.h"
#include "Parser.h"
#include "CmdList.h"

class Window : public Gtk::Window
{
public:
    Window();
    Settings* get_settings();
    TextView* get_text_view();
    CmdList* get_cmd_list();
    Shell* get_shell();
    Parser* get_parser();
private:
    Gtk::Box vbox;
    Gtk::ScrolledWindow scrolled_window;
    Settings* settings;
    TextView* text_view;
    CmdList* cmd_list;
    Shell* shell;
    Parser* parser;
};

#endif