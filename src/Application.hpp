#ifndef MAIN_APPLICATION_H
#define MAIN_APPLICATION_H

#include <gtkmm.h>


class Application : public Gtk::Application
{
public:
    static Glib::RefPtr<Application> create();
protected:
    explicit Application();
    // override default signal handlers
    void on_startup() override;
    void on_activate(void) override;
    

private:
    void create_window(void);
    void create_menu(void);

    void on_window_hide(Gtk::Window* window);
    void on_menu_file_open();
    void on_menu_file_new();
    void on_menu_file_save();
    void on_menu_file_quit();
    void on_menu_edit_copy();
    void on_menu_edit_paste();
    void on_menu_edit_cut();
    void on_menu_edit_delete();
    void on_menu_help_about();
};

#endif /* MAIN_APPLICATION_H */

