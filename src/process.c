#include "process.h"

gboolean zoom_key_pressed(GtkWidget* window, GdkEventKey* event){
    if((event->state & GDK_CONTROL_MASK) && (event->keyval == GDK_KEY_plus || event->keyval == GDK_KEY_KP_Add)){
        editor_zoom_in(window);
        return TRUE;
    }else if((event->state & GDK_CONTROL_MASK) && (event->keyval == GDK_KEY_minus || event->keyval == GDK_KEY_KP_Subtract)){
        editor_zoom_out(window);
        return TRUE;
    }else{
        return FALSE;
    }
}