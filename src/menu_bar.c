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
#include "menu_bar.h"
void menu_zoom_in(GtkWidget * call, gpointer window){
    editor_zoom_in(window);
}
void menu_zoom_out(GtkWidget * call, gpointer window){
    editor_zoom_out(window);
}
void menu_application_quit(GtkWidget * call, gpointer app){
    if(buffer_has_changed){
        to_save_at_quit();
    }
    if(!buffer_has_changed){
        g_application_quit(app);
    }
}
void menu_show_search_replace(GtkWidget * widget, gpointer user_data){
    if(gtk_widget_get_visible(search_replace_box) == FALSE){
        gtk_widget_show(search_replace_box);
    }else{
        gtk_widget_hide(search_replace_box);
        clear_highlights(buffer);
    }
}