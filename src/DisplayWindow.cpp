
#include "DisplayWindow.hpp"

DisplayWindow::DisplayWindow(const Glib::ustring windowLabel) :
    Gtk::Frame(windowLabel)
{
    set_size_request(400, 800);
    set_shadow_type(Gtk::SHADOW_IN);
//    set_shadow_type(Gtk::SHADOW_ETCHED_IN);
}

