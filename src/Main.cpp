#include "Window.h"
#include <gtkmm/application.h>

int main(int argc, char** argv)
{
    auto app = Gtk::Application::create("org.gtkmm.Shell");
    return app->make_window_and_run<Window>(argc, argv);
}