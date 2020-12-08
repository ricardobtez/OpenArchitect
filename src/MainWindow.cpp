
#include <iostream>
#include <gtkmm/toolbar.h>
#include <gtkmm/toolbutton.h>
#include "MainWindow.hpp"

MainWindow::MainWindow() :
    Gtk::ApplicationWindow(),
    m_box(Gtk::ORIENTATION_VERTICAL)
{
    // Sets the title of the window. Property of the Gtk::Window super class
    set_title(Glib::ustring("Open Architect"));
    Glib::RefPtr< const Gdk::Screen > rRefScreen = get_screen();
    
    int width = rRefScreen->get_width() / 2;
    int heigth = rRefScreen->get_height() / 2;
    set_default_size(width, heigth);

    add(m_box);

    add_action("copy",
        sigc::mem_fun(*this, &MainWindow::on_menu_others));

    add_action("paste",
        sigc::mem_fun(*this, &MainWindow::on_menu_others));

    m_refChoice = add_action("preferences",
        sigc::mem_fun(*this, &MainWindow::on_toolbar_new_button));
    m_refToggle = add_action_bool("sometoggle",
        sigc::mem_fun(*this, &MainWindow::on_menu_toggle), false);
        
    // Help menu
    add_action("about", sigc::mem_fun(*this, &MainWindow::on_menu_others));
    Gtk::ToolButton* newToolButton = new Gtk::ToolButton();
    newToolButton->set_icon_name("document-new"); // application-exit
    newToolButton->set_tooltip_text("New Project");
    newToolButton->set_visible(true);
    newToolButton->set_can_focus(false);
    newToolButton->set_homogeneous(true);
    newToolButton->set_expand(false);

    Gtk::Toolbar* toolbar = new Gtk::Toolbar();
    toolbar->set_visible(true);
    toolbar->set_can_focus(false);

    toolbar->insert(*newToolButton, 0, sigc::slot<void>(sigc::mem_fun(*this, &MainWindow::on_toolbar_new_button)));

    m_box.pack_start(*toolbar, Gtk::PACK_SHRINK);

}

MainWindow::~MainWindow(void)
{

}


void MainWindow::on_menu_others()
{
    std::cout << "A menu item was selected." << std::endl;
}

void MainWindow::on_toolbar_new_button()
{
    std::cout << "Toolbar|New button pressed" << std::endl;
}

void MainWindow::on_menu_choices_other(const int parameter)
{
    //The radio action's state does not change automatically:
    m_refChoice->change_state(parameter);

    Glib::ustring message;
    if (parameter == 1)
        message = "Choice 1 was selected";
    else
        message = "Choice 2 was selected";

    std::cout << message << std::endl;
}

void MainWindow::on_menu_toggle(void)
{
    bool active = false;
    m_refToggle->get_state(active);

    // The toggle action's state does not change automatically
    active = !active;
    m_refToggle->change_state(active);

    Glib::ustring message;

    if (active)
        message = "Toggle is active";
    else
        message = "Toggle is inactive";

    std::cout << message << std::endl;
}





