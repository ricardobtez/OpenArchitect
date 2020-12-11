#include <iostream>
//#include <giomm/menu.h>
//#include <gtkmm/separatormenuitem.h>
#include "MainAppActions.hpp"
#include "Application.hpp"
#include "MainWindow.hpp"

Application::Application() :
    Gtk::Application("gtkmm-application.com")
{
}

Glib::RefPtr<Application> Application::create()
{
    return Glib::RefPtr<Application>(new Application());
}

void Application::create_window()
{
    auto window = new MainWindow();
    
    // Makes sure the application runs as long as the window is open
    add_window(*window);

    // Gtk::Application::add_window() connects a signal handler to the window's
    // signal_hide(). That handler removes the window from the application.
    // If it's the last window to be removed, the application stops running.
    // Gtk::Window::set_application() does not connect a signal handler, but is
    // otherwise equivalent to Gtk::Application::add_window().

    // Delete the window when it is hidden.
    window->signal_hide().connect(sigc::bind<Gtk::Window*>(
        sigc::mem_fun(*this, &Application::on_window_hide), window));

    // let's show a window.
    window->show_all();
}

void Application::create_menu()
{
    Glib::RefPtr<Gio::Menu> appMenu = Gio::Menu::create();
    Glib::RefPtr<Gio::Menu> menuBar = Gio::Menu::create();
    int pos = 0;

    // Creates all the Menus for the menu bar
    for (auto menuElements : mainMenuElements)
    {
        Glib::RefPtr<Gio::Menu> currSubMenu = Gio::Menu::create();

        for (auto submenu : menuElements.submenu)
        {
            if (submenu.submenuLabel != "" && submenu.action != "")
                currSubMenu->append(submenu.submenuLabel, submenu.action);
            //else
            //    currSubMenu->append("", "");
        }

        menuBar->insert_submenu(pos++, menuElements.menuText, currSubMenu);
    }
    pos = 0;

    // Creates the application menu
    for (auto menuElements : appMenuElements)
    {
        Glib::RefPtr<Gio::Menu> currSubMenu = Gio::Menu::create();

        for (auto submenu : menuElements.submenu)
        {
            if (submenu.submenuLabel != "" && submenu.action != "")
                currSubMenu->append(submenu.submenuLabel, submenu.action);
        }

        appMenu->insert_submenu(pos++, menuElements.menuText, currSubMenu);
    }

    for (auto acc : mainAppAccelerators)
    {
        set_accel_for_action(acc.action, acc.accelerator);
    }

    set_app_menu(appMenu);
    set_menubar(menuBar);
}

void Application::on_startup()
{
    // Call of the base class function
    Gtk::Application::on_startup();

    // Create actions for menus and toolbars.
    // We can use add_action()because Gtk::Application derives from Gio::ActionMap
    //File|New sub menu:
    add_action("new",
        sigc::mem_fun(*this, &Application::on_menu_file_new));
        
    add_action("open",
        sigc::mem_fun(*this, &Application::on_menu_file_open));

    add_action("save",
        sigc::mem_fun(*this, &Application::on_menu_file_save));
        
    // File menu
    add_action("quit", sigc::mem_fun(*this, &Application::on_menu_file_quit));

    // Help menu
    add_action("about", sigc::mem_fun(*this, &Application::on_menu_help_about));

    add_action("copy", sigc::mem_fun(*this, &Application::on_menu_edit_copy));

    add_action("paste", sigc::mem_fun(*this, &Application::on_menu_edit_paste));

    add_action("cut", sigc::mem_fun(*this, &Application::on_menu_edit_cut));

    add_action("delete", sigc::mem_fun(*this, &Application::on_menu_edit_delete));

    create_menu();
}

void Application::on_activate()
{
    create_window();
}

void Application::on_window_hide(Gtk::Window* window)
{
    std::cout << "Deleting Window" <<std::endl;
    delete window;
}

void Application::on_menu_file_new()
{
    std::cout << "A File|New Item was selected\n";
}

void Application::on_menu_file_open()
{
    std::cout << "A File|Open Item was selected\n";
}

void Application::on_menu_file_save()
{
    std::cout << "A File|Save Item was selected\n";
}

void Application::on_menu_file_quit()
{
    std::cout << G_STRFUNC << std::endl;
    quit();
    
    // Gio::Application::quit() will make Gio::Application::run() return,
    // but it's a crude way of ending the program. The window is not removed
    // from the application. Neither the window's nor the application's
    // destructors will be called, because there will be remaining reference
    // counts in both of them. If we want the destructors to be called, we
    // must remove the window from the application. One way of doing this
    // is to hide the window.
    std::vector<Gtk::Window*> windows = get_windows();
    if (windows.size() > 0)
        windows[0]->hide(); // In this simple case, we know there is only one window
}

void Application::on_menu_edit_copy()
{
    std::cout << "Edit|Copy selected" << std::endl;
}

void Application::on_menu_edit_paste()
{
    std::cout << "Edit|Paste selected" << std::endl;
}

void Application::on_menu_edit_cut()
{
    std::cout << "Edit|Cut selected" << std::endl;
}

void Application::on_menu_edit_delete()
{
    std::cout << "Edit|Delete selected" << std::endl;
}

void Application::on_menu_help_about()
{
    std::cout << "Help|About was selected." << std::endl;
}

