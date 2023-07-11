#include "Window.h"

Window::Window() : vbox(Gtk::Orientation::VERTICAL)
{
    set_title("Terminal");
    set_default_size(1200, 750);
    set_child(vbox);

    settings = new Settings;
    text_view = new TextView(this);
    command_list = new CommandList;
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

CommandList* Window::get_command_list()
{
    return command_list;
}

Shell* Window::get_shell()
{
    return shell;
}

Parser* Window::get_parser()
{
    return parser;
}