#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "Window.h"

class TextArea : public Gtk::TextView
{
public:
    TextArea();
    void set_prefix(std::string prefix);
    std::string get_prefix();
    void set_shell(Shell* shell);
    Shell* get_shell();
private:
    bool on_key_pressed(guint keyval, guint keycode, Gdk::ModifierType state);
    Shell* shell;
    std::string prefix;
};

#endif