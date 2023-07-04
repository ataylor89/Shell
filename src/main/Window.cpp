#include "Window.h"

Window::Window() : vbox(Gtk::Orientation::VERTICAL)
{
    set_title("Terminal");
    set_default_size(800, 600);
    
    vbox.set_margin_top(20);
    vbox.set_margin_start(10);
    vbox.set_margin_end(10);
    vbox.set_margin_bottom(10);
    set_child(vbox);

    settings = new Settings;
    text_view = new TextView(this);
    shell = new Shell(this);
    parser = new Parser(this);

    scrolled_window.set_policy(Gtk::PolicyType::NEVER, Gtk::PolicyType::AUTOMATIC);
    scrolled_window.set_expand();
    scrolled_window.set_child(*text_view);
    vbox.append(scrolled_window);
}

Settings* Window::get_settings()
{
    return settings;
}

TextView* Window::get_text_view()
{
    return text_view;
}

Shell* Window::get_shell()
{
    return shell;
}

Parser* Window::get_parser()
{
    return parser;
}