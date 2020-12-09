#ifndef DISPLAY_WINDOW_H
#define DISPLAY_WINDOW_H

#include <vector>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/widget.h>

class DisplayWindow: public Gtk::ScrolledWindow
{
public:
    DisplayWindow();

protected:
    void add(Gtk::Widget& widget) override;
private:
    //std::vector<Gtk::Widget&> m_childs;
};

#endif /* DISPLAY_WINDOW_H */

