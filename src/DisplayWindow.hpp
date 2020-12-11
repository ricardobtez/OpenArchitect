#ifndef DISPLAY_WINDOW_H
#define DISPLAY_WINDOW_H

#include <gtkmm/paned.h>

class DisplayWindow: public Gtk::Paned
{
public:
    DisplayWindow(const Gtk::Orientation orientation);
};

#endif /* DISPLAY_WINDOW_H */

