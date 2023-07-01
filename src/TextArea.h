#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "Shell.h"
#include <gtkmm.h>

class TextArea : public Gtk::TextView
{
public:
    TextArea();
private:
    bool on_key_pressed(guint keyval, guint keycode, Gdk::ModifierType state);

    Shell shell;
    Glib::RefPtr<Gtk::TextBuffer> buffer;
    const string prefix;
};

#endif