/*
Nilgiri Text Editor: A simple lightweight text/code editor developed as a student project!  
Copyright (C) 2024 NEERAJ R RUGI

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
