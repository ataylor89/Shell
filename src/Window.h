#ifndef WINDOW_H
#define WINDOW_H

#include "TextArea.h"
#include <gtkmm.h>

class Window : public Gtk::Window
{
public:
    Window();
private:
    Gtk::Box vbox;
    Gtk::ScrolledWindow scrolled_window;
    TextArea text_area;
};

#endif