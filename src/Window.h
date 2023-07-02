#ifndef WINDOW_H
#define WINDOW_H

class Window;
class Settings;
class TextArea;
class Shell;
class Parser;
class Command;

#include <gtkmm.h>
#include "Settings.h"
#include "TextArea.h"
#include "Shell.h"
#include "Parser.h"

class Window : public Gtk::Window
{
public:
    Window();
    Settings* get_settings();
    TextArea* get_text_area();
    Shell* get_shell();
    Parser* get_parser();
private:
    Gtk::Box vbox;
    Gtk::ScrolledWindow scrolled_window;
    Settings* settings;
    TextArea* text_area;
    Shell* shell;
    Parser* parser;
};

#endif