
#ifndef MAINAPP_ACTIONS_H
#define MAINAPP_ACTIONS_H
#include <vector>
#include <glibmm/ustring.h>

typedef struct tstSubMenuData
{
    Glib::ustring submenuLabel;
    Glib::ustring action;
}tstSubMenuData;

typedef struct tstMenuData
{
    std::vector<tstSubMenuData> submenu;
    Glib::ustring menuText;
}tstMenuData;

typedef struct tstAcceleratorActions
{
    Glib::ustring action;
    Glib::ustring accelerator;
}tstAcceleratorActions;

const std::vector<tstSubMenuData> fileSubmenu =
{
    { "_New Project", "app.new" },
    { "_Open Project", "app.open" },
    { "_Save Project", "app.save" },
    { "", "" },
    { "_Quit", "app.quit" }
};

const std::vector<tstSubMenuData> editSubMenu =
{
    { "_Copy", "app.copy" },
    { "_Paste", "app.paste" },
    { "C_ut", "app.cut" },
    { "_Delete", "app.delete" }
};

const std::vector<tstSubMenuData> viewSubMenu =
{
    { "", "" }
};

const std::vector<tstSubMenuData> helpSubMenu =
{
    { "_About", "app.about" }
};


const std::vector<tstMenuData> mainMenuElements =
{
    { fileSubmenu , "_File" },
    { editSubMenu, "_Edit" },
    { viewSubMenu, "_View" },
    { helpSubMenu, "_Help" }
};

const std::vector<tstMenuData> appMenuElements =
{
    { fileSubmenu, "_File" }
};


const std::vector<tstAcceleratorActions> mainAppAccelerators =
{
    { "app.new",  "<Primary>n" },
    { "app.open", "<Primary>o" },
    { "app.save", "<Primary>s" },
    { "app.quit", "<Primary>q" },
    { "app.copy", "<Primary>c" },
    { "app.paste", "<Primary>p" },
    { "app.cut", "<Primary>x" },
    { "app.help", "<Primary>h" }
};
#endif /* MAINAPP_ACTIONS_H */
