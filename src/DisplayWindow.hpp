#ifndef DISPLAY_WINDOW_H
#define DISPLAY_WINDOW_H

#include <gtkmm/frame.h>
#include <glibmm/ustring.h>

class DisplayWindow: public Gtk::Frame
{
public:
    DisplayWindow(const Glib::ustring windowlabel);
};

#endif /* DISPLAY_WINDOW_H */

