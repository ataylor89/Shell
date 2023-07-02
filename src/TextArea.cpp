#include "TextArea.h"

TextArea::TextArea(Window* window)
{
    this->window = window;

    set_editable(true);
    set_wrap_mode(Gtk::WrapMode::WORD_CHAR);

    auto buffer = Gtk::TextBuffer::create();
    Settings* settings = window->get_settings();
    std::string prefix = settings->get_prefix();
    buffer->set_text(prefix);
    set_buffer(buffer);

    auto controller = Gtk::EventControllerKey::create();
    controller->signal_key_pressed().connect(
        sigc::mem_fun(*this, &TextArea::on_key_pressed), false);
    add_controller(controller);
}

void TextArea::clear()
{
    auto buffer = get_buffer();
    Settings* settings = window->get_settings();
    std::string prefix = settings->get_prefix();
    buffer->set_text(prefix);
}

void TextArea::append(std::string text)
{
    auto buffer = get_buffer();
    buffer->insert_at_cursor(text);
}

void TextArea::append_prefix()
{
    auto buffer = get_buffer();
    Settings* settings = window->get_settings();
    std::string prefix = settings->get_prefix();
    buffer->insert_at_cursor(prefix);
}

bool TextArea::on_key_pressed(guint keyval, guint keycode, Gdk::ModifierType state)
{
    if (keyval == GDK_KEY_Return)
    {
        Settings* settings = window->get_settings();
        const std::string prefix = settings->get_prefix();
        const int len = prefix.length();

        auto buffer = get_buffer();
        auto cursor = buffer->get_insert();
        Gtk::TextBuffer::iterator end = buffer->get_iter_at_mark(cursor);
        Gtk::TextBuffer::iterator start = end;

        while (start.get_char() != '\n' && start != buffer->begin())
        {
            start--;
        }

        start.forward_chars(start == buffer->begin() ? len : len + 1);
        const std::string command = buffer->get_text(start, end);

        Shell* shell = window->get_shell();
        shell->exec(command);
        return true;
    }
    else if (keyval == GDK_KEY_BackSpace)
    {
        Settings* settings = window->get_settings();
        const std::string prefix = settings->get_prefix();
        const int len = prefix.length();

        auto buffer = get_buffer();
        auto cursor = buffer->get_insert();
        Gtk::TextBuffer::iterator iter = buffer->get_iter_at_mark(cursor);
        iter.backward_chars(len);

        if (iter == buffer->begin())
        {
            return true;
        }

        iter.backward_chars(1);

        if (iter.get_char() == '\n')
        {
            return true;
        }
    }
    return false;
}