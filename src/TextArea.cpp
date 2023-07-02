#include "TextArea.h"

TextArea::TextArea() : prefix("% ")
{
    set_editable(true);
    set_wrap_mode(Gtk::WrapMode::WORD_CHAR);
    Glib::RefPtr<Gtk::TextBuffer> buffer = Gtk::TextBuffer::create();
    buffer->set_text(prefix);
    set_buffer(buffer);

    auto controller = Gtk::EventControllerKey::create();
    controller->signal_key_pressed().connect(
        sigc::mem_fun(*this, &TextArea::on_key_pressed), false);
    add_controller(controller);
}

bool TextArea::on_key_pressed(guint keyval, guint keycode, Gdk::ModifierType state)
{
    if (keyval == GDK_KEY_Return)
    {
        Glib::RefPtr<Gtk::TextBuffer> buffer = this->get_buffer();
        Glib::RefPtr<Gtk::TextBuffer::Mark> cursor = buffer->get_insert();
        Gtk::TextBuffer::iterator end = buffer->get_iter_at_mark(cursor);
        Gtk::TextBuffer::iterator start = end;
        while (start.get_char() != '\n' && start != buffer->begin())
            start--;
        start.forward_chars(start == buffer->begin() ? 2 : 3);
        std::string command = buffer->get_text(start, end);
        shell->exec(command);
        return true;
    }
    else if (keyval == GDK_KEY_BackSpace)
    {
        Glib::RefPtr<Gtk::TextBuffer> buffer = this->get_buffer();
        Glib::RefPtr<Gtk::TextBuffer::Mark> cursor = buffer->get_insert();
        Gtk::TextBuffer::iterator iter = buffer->get_iter_at_mark(cursor);
        iter.backward_chars(2);
        if (iter == buffer->begin())
            return true;
        iter.backward_chars(1);
        if (iter.get_char() == '\n')
            return true;
    }
    return false;
}

void TextArea::set_prefix(std::string prefix) 
{
    this->prefix = prefix;
}

std::string TextArea::get_prefix()
{
    return prefix;
}

void TextArea::set_shell(Shell* shell) 
{
    this->shell = shell;
}

Shell* TextArea::get_shell()
{
    return shell;
}