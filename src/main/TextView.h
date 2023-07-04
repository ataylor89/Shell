#ifndef TEXT_AREA_H
#define TEXT_AREA_H

#include "Window.h"

class TextView : public Gtk::TextView
{
public:
    TextView(Window* window);
    void clear();
    void append(std::string text);
    void append_prefix();
private:
    bool on_key_pressed(guint keyval, guint keycode, Gdk::ModifierType state);
    Window* window;
};

#endif