#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm/applicationwindow.h>
#include <gtkmm/grid.h>
#include <gtkmm/builder.h>


class MainWindow : public Gtk::ApplicationWindow
{
public:
    MainWindow();
    virtual ~MainWindow();
protected:
    // Signal handlers
    void on_menu_others(void);

    // Child widgets
    Gtk::Grid m_grid;

private:
    void on_toolbar_new_button(void);
    void on_toolbar_exit_button(void);
};

#endif /* MAIN_WINDOW_H */

