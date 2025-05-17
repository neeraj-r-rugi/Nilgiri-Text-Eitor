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