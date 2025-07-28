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
#include "fonts.h"

void editor_apply_font_size(GtkWidget* window, short int font_size){
    show_zoom_overlay();
    PangoFontDescription *editor_font = pango_font_description_new();
    pango_font_description_set_family(editor_font, "monospace");
    pango_font_description_set_size(editor_font, font_size * PANGO_SCALE);
    gtk_widget_override_font(window, editor_font);
    pango_font_description_free(editor_font);


}

void editor_zoom_in(GtkWidget * window){
    if(CURRENT_FONT_SIZE < 54){
        CURRENT_FONT_SIZE += 1;
        editor_apply_font_size(window, CURRENT_FONT_SIZE);
    }
}

void editor_zoom_out(GtkWidget * window){
    if(CURRENT_FONT_SIZE > 6){
        CURRENT_FONT_SIZE -= 1;
        editor_apply_font_size(window, CURRENT_FONT_SIZE);
    }
}