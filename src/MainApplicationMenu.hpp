
#ifndef MAIN_APP_MENU_H
#define MAIN_APP_MENU_H

#include <glibmm/ustring.h>


typedef struct tstMenuData
{
    const Glib::ustring nameAction;
    const Glib::ustring nameMenuItem;
    const Glib::ustring acceleratorSignal;
}tstMenuData;

tstMenuData FileMenuStructure[]
{
    {"app.new", "_New", ""},    /*! New Menu data */
    {"app.open", "_Open", ""}   /*! Open Menu date */
};

#endif /* MAIN_APP_MENU_H */
