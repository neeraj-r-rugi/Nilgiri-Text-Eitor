#include "overlays.h"

//Variable Declaration
static guint zoom_overlay_timeout = 0;

/************************************************************************************************************ */
//Zoom Overlay
static void hide_zoom_popup(){
    gtk_widget_hide(zoom_popup);
    zoom_overlay_timeout = 0;
    printf("Overlay Removed\n");
}

static gboolean hide_zoom_popup_cb(){
    hide_zoom_popup();
    return G_SOURCE_REMOVE;
}

void show_zoom_overlay(){
    printf("Overlay Shown\n");
    char buff[64];
    int font_per = (DEFAULT_FONT_SIZE / CURRENT_FONT_SIZE) * 100;
    snprintf(buff, sizeof(buff), "Zoom Level: %d%%", font_per);
    gtk_label_set_text(GTK_LABEL(zoom_popup), buff);
    gtk_widget_show(zoom_popup);
    if(zoom_overlay_timeout != 0){
        g_source_remove(zoom_overlay_timeout);
    }
    
    zoom_overlay_timeout = g_timeout_add(2000, hide_zoom_popup_cb, NULL);
}
/************************************************************************************************************ */