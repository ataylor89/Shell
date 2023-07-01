#include "TextArea.h"
#include <string>

using namespace std;

TextArea::TextArea()
: prefix("% ")
{
    this->set_editable(true);
    buffer = Gtk::TextBuffer::create();
    buffer->set_text(prefix);
    this->set_buffer(buffer);

    auto controller = Gtk::EventControllerKey::create();
    controller->signal_key_pressed().connect(
        sigc::mem_fun(*this, &TextArea::on_key_pressed), false);
    add_controller(controller);
}

bool TextArea::on_key_pressed(guint keyval, guint keycode, Gdk::ModifierType state)
{
    if (keyval == GDK_KEY_Return) {
        Glib::RefPtr<Gtk::TextBuffer::Mark> cursor = buffer->get_insert();
        Gtk::TextBuffer::iterator end = buffer->get_iter_at_mark(cursor);
        Gtk::TextBuffer::iterator start = end;
        while (start.get_char() != '\n' && start != buffer->begin())
            start--;
        start.forward_chars(2);
        string command = buffer->get_text(start, end);
        string output = shell.exec(command);
        buffer->insert_at_cursor("\n" + output + prefix);
        return true;       
    }
    if (keyval == GDK_KEY_BackSpace) {
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