#ifndef WINDOW_H
#define WINDOW_H

class Window;
class TextView;
class Parser;
class Command;

#include <gtkmm.h>
#include "Settings.h"
#include "Parser.h"
#include "TextView.h"

class Window : public Gtk::Window
{
public:
    Window();
    Settings* get_settings();
    Parser* get_parser();
    TextView* get_text_view();
private:
    Gtk::Box vbox;
    Gtk::ScrolledWindow scrolled_window;
    Settings* settings;
    Parser* parser;
    TextView* text_view;
};

#endif