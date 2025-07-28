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
#include "overlays.h"

//Variable Declaration
static guint zoom_overlay_timeout = 0;
static guint file_saved_overlay_timeout = 0;

/************************************************************************************************************ */
//Zoom Overlay
static void hide_zoom_popup(){
    gtk_widget_hide(zoom_popup);
    zoom_overlay_timeout = 0;
}

static gboolean hide_zoom_popup_cb(){
    hide_zoom_popup();
    return G_SOURCE_REMOVE;
}

void show_zoom_overlay(){
    char buff[64];
    int font_per = ((float)CURRENT_FONT_SIZE / (float)DEFAULT_FONT_SIZE) * 100;
    snprintf(buff, sizeof(buff), "Zoom Level: %d%%", font_per);
    gtk_label_set_text(GTK_LABEL(zoom_popup), buff);
    gtk_widget_show(zoom_popup);
    if(zoom_overlay_timeout != 0){
        g_source_remove(zoom_overlay_timeout);
    }
    
    zoom_overlay_timeout = g_timeout_add(2000, hide_zoom_popup_cb, NULL);
}

void show_file_saved_overlay(){
    char buff[64];
    int font_per = ((float)CURRENT_FONT_SIZE / (float)DEFAULT_FONT_SIZE) * 100;
    snprintf(buff, sizeof(buff), "File Saved!");
    gtk_label_set_text(GTK_LABEL(file_saved_popup), buff);
    gtk_widget_show(file_saved_popup);
    if(file_saved_overlay_timeout != 0){
        g_source_remove(file_saved_overlay_timeout);
    }
    
    file_saved_overlay_timeout = g_timeout_add(2000, hide_file_saved_popup_cb, NULL);


}

static void hide_file_saved_popup(){
    gtk_widget_hide(file_saved_popup);
    file_saved_overlay_timeout = 0;

}
static gboolean hide_file_saved_popup_cb(){
    hide_file_saved_popup();
    return G_SOURCE_REMOVE;
}
/************************************************************************************************************ */