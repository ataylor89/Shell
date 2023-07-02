#include "Window.h"

Window::Window() : vbox(Gtk::Orientation::VERTICAL)
{
    set_title("Shell");
    set_default_size(800, 600);
    
    vbox.set_margin_top(20);
    vbox.set_margin_start(10);
    vbox.set_margin_end(10);
    vbox.set_margin_bottom(10);
    set_child(vbox);

    text_area = new TextArea;
    shell = new Shell;
    text_area->set_shell(shell);
    shell->set_text_area(text_area);

    scrolled_window.set_policy(Gtk::PolicyType::NEVER, Gtk::PolicyType::AUTOMATIC);
    scrolled_window.set_expand();
    scrolled_window.set_child(*text_area);
    vbox.append(scrolled_window);
}