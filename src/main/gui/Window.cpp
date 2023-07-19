#include "gui/Window.h"
#include <filesystem>

Window::Window() : vbox(Gtk::Orientation::VERTICAL)
{
    set_title("Terminal");
    set_default_size(1200, 750);
    set_child(vbox);

    settings = new Settings;
    settings->load();
    parser = new Parser(this);
    text_view = new TextView(settings, parser);

    scrolled_window.set_policy(Gtk::PolicyType::NEVER, Gtk::PolicyType::AUTOMATIC);
    scrolled_window.set_expand();
    scrolled_window.set_child(*text_view);
    vbox.append(scrolled_window);
}

Settings* Window::get_settings()
{
    return settings;
}

Parser* Window::get_parser()
{
    return parser;
}

TextView* Window::get_text_view()
{
    return text_view;
}