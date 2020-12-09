
#include "DisplayWindow.hpp"

DisplayWindow::DisplayWindow()
{

}

void DisplayWindow::add(Gtk::Widget& widget)
{
    Gtk::ScrolledWindow::add(widget);
    //m_childs.push_back(widget);
}
