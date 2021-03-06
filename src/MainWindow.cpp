
#include <iostream>
#include <gtkmm/toolbar.h>
#include <gtkmm/toolbutton.h>
#include <gtkmm/paned.h>
#include <gtkmm/filechooserbutton.h>
#include <gtkmm/colorselection.h>
#include <gtkmm/filechooserwidget.h>
#include <gtkmm/appchooserwidget.h>
#include <gtkmm/frame.h>
#include "MainWindow.hpp"
#include "DisplayWindow.hpp"

MainWindow::MainWindow() :
    Gtk::ApplicationWindow(),
    m_currentPages(new Gtk::Notebook()),
    m_projectView(new Gtk::TreeView())
{
    // Sets the title of the window. Property of the Gtk::Window super class
    set_title(Glib::ustring("Open Architect"));
    Glib::RefPtr< const Gdk::Screen > rRefScreen = get_screen();
    
    int width = rRefScreen->get_width() / 2;
    int heigth = rRefScreen->get_height() / 2;
    set_default_size(width, heigth);

    m_grid.set_column_homogeneous(true);
    add(m_grid);

    add_action("copy",
        sigc::mem_fun(*this, &MainWindow::on_menu_others));

    add_action("paste",
        sigc::mem_fun(*this, &MainWindow::on_menu_others));

    // Help menu
    add_action("about", sigc::mem_fun(*this, &MainWindow::on_menu_others));

    Gtk::ToolButton* newToolButton = new Gtk::ToolButton();
    newToolButton->set_icon_name("document-new"); // application-exit
    newToolButton->set_tooltip_text("New Project");
    newToolButton->set_visible(true);
    newToolButton->set_can_focus(false);
    newToolButton->set_homogeneous(true);
    newToolButton->set_expand(false);

    Gtk::ToolButton* exitToolbarButton = new Gtk::ToolButton();
    exitToolbarButton->set_icon_name("application-exit");
    exitToolbarButton->set_tooltip_text("Exit Project");
    exitToolbarButton->set_visible(true);
    exitToolbarButton->set_can_focus(false);
    exitToolbarButton->set_homogeneous(true);
    exitToolbarButton->set_expand(false);

    Gtk::Toolbar* toolbar = new Gtk::Toolbar();
    toolbar->set_visible(true);
    toolbar->set_can_focus(false);

    toolbar->insert(*exitToolbarButton, 0,
                    sigc::slot<void>(
                        sigc::mem_fun(*this, &MainWindow::on_toolbar_exit_button)));
    toolbar->insert(*newToolButton, 0,
                    sigc::slot<void>(
                        sigc::mem_fun(*this, &MainWindow::on_toolbar_new_button)));

    DisplayWindow* display = new DisplayWindow("*New Element");
    Gtk::FileChooserButton* button = new Gtk::FileChooserButton("FileChooser button");
    m_currentPages->append_page(*display, display->get_label());
    display->show();

    m_grid.attach(*toolbar, 0, 0, 1, 1);
    m_grid.attach(*button, 1, 0, 1, 1);
    m_grid.attach(*m_projectView, 0, 1, 1, 1);
    m_grid.attach(*m_currentPages, 1, 1, 3, 3);
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

void MainWindow::on_toolbar_exit_button()
{
    std::cout << "Toolbar|Exit button pressed" << std::endl;
}

