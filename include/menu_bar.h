#ifndef MENU_BAR_H
#define MENU_BAR_H
#endif
#include "defines.h"

/*
    @brief: Functions to implement functions of the Menu Bar Ribbon
*/

//Function prototypes

/*
    @brief: Zooms in the font, called via the menu bar
    @param: The GtkWindow to be zoomed in
*/
void menu_zoom_in(GtkWidget * ,gpointer);
/*
    @brief: Zooms out the font, called via the menu bar
    @param: The GtkWindow to be zoomed out
*/
void menu_zoom_out(GtkWidget *,gpointer );
/*
    @brief: Quits the application
    @param: The Application to be quit
*/
void menu_application_quit(GtkWidget * ,gpointer );
/*
    @brief: Quits the application
    @param: The Application to be quit
*/
void menu_show_search_replace(GtkWidget *, gpointer);
