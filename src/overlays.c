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