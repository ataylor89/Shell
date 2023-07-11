#ifndef WINDOW_H
#define WINDOW_H

class Window;
class TextView;
class Shell;
class Parser;
struct ParseTree;
class Command;

#include <gtkmm.h>

#include <string>
#include <vector>
#include <map>

#include "Util.h"
#include "StatusCode.h"
#include "CommandType.h"
#include "CommandList.h"
#include "Settings.h"
#include "TextView.h"
#include "Shell.h"
#include "Parser.h"
#include "ParseTree.h"
#include "Command.h"

class Window : public Gtk::Window
{
public:
    Window();
    Settings* get_settings();
    TextView* get_text_view();
    Shell* get_shell();
private:
    Gtk::Box vbox;
    Gtk::ScrolledWindow scrolled_window;
    Settings* settings;
    TextView* text_view;
    Shell* shell;
};

#endif