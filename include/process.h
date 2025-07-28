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

#ifndef PROCESS_H
#define PROCESS_H
#include "defines.h"

//Function Prototype


/*
    !!
    @brief: UPDATE
    @param: UPDATE
    @param: UPDATE
*/
gboolean zoom_key_pressed(GtkWidget*, GdkEventKey*);
/*
    !!
    @brief: UPDATE
    @param: UPDATE
    @param: UPDATE
*/
gboolean quit_key_pressed(GtkWidget *, GdkEventKey *, gpointer );
/*
    !!
    @brief: UPDATE
    @param: UPDATE
    @param: UPDATE
*/
gboolean toggle_dark_theme(GtkWidget*, GdkEventKey*);
/*
    !!
    @brief: UPDATE
    @param: UPDATE
    @param: UPDATE
*/
void set_theme(gboolean);
/*
    !!
    @brief: UPDATE
    @param: UPDATE
    @param: UPDATE
*/
gboolean search_key_pressed(GtkWidget * , GdkEventKey * , gpointer );
/*
    !!
    @brief: UPDATE
    @param: UPDATE
    @param: UPDATE
*/
gboolean show_search_replace_box(GtkWidget * , GdkEventKey * , gpointer );

gboolean highlight_key_pressed(GtkWidget * , GdkEventKey * , gpointer );


gboolean save_key_pressed(GtkWidget* , GdkEventKey* );

void save_at_quit_no(GtkWidget * , gpointer );

void save_at_quit_yes(GtkWidget * , gpointer );

void set_file_language();

void unset_file_language();

char * get_css_file_path(); 

#endif