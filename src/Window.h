#ifndef WINDOW_H
#define WINDOW_H

class TextArea;
class Shell;

#include <gtkmm.h>
#include <string>
#include "TextArea.h"
#include "Shell.h"

class Window : public Gtk::Window
{
public:
    Window();
private:
    Gtk::Box vbox;
    Gtk::ScrolledWindow scrolled_window;
    TextArea *text_area;
    Shell *shell;
};

#endif