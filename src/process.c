#include "process.h"

gboolean zoom_key_pressed(GtkWidget* window, GdkEventKey* event){
    if((event->state & GDK_CONTROL_MASK) && (event->keyval == GDK_KEY_equal|| event->keyval == GDK_KEY_KP_Add)){
        editor_zoom_in(window);
        return TRUE;
    }else if((event->state & GDK_CONTROL_MASK) && (event->keyval == GDK_KEY_minus || event->keyval == GDK_KEY_KP_Subtract)){
        editor_zoom_out(window);
        return TRUE;
    }else{
        return FALSE;
    }
}

gboolean save_key_pressed(GtkWidget* window, GdkEventKey* event){
    if((event->state & GDK_CONTROL_MASK) && (event->keyval == GDK_KEY_s)){
        save_buffer_to_file();
        return TRUE;
    }else{
        return FALSE;
    }
}

gboolean quit_key_pressed(GtkWidget * window, GdkEventKey * event, gpointer user_data){
    if(((event->state && GDK_CONTROL_MASK) && (event->keyval == GDK_KEY_Escape))){
        if(buffer_has_changed){
            to_save_at_quit();
        }
        if(!buffer_has_changed){
            g_application_quit(user_data);
        }
        return TRUE;
    }
    return FALSE;

}

gboolean show_search_replace_box(GtkWidget * window, GdkEventKey * event, gpointer user_data){
    if((event->state & GDK_CONTROL_MASK) && (event->keyval == GDK_KEY_F || event->keyval == GDK_KEY_f)){
        if(gtk_widget_get_visible(search_replace_box) == FALSE){
            gtk_widget_show(search_replace_box);
        }else{
            gtk_widget_hide(search_replace_box);
            clear_highlights(user_data);
        }
        return TRUE;
    }
    return FALSE;

}

/******************************************************************************************* */
//Toggles Dark Theme
gboolean toggle_dark_theme(GtkWidget *window, GdkEventKey *event) {
    if ((event->state & GDK_MOD1_MASK) && (event->keyval == GDK_KEY_D || event->keyval == GDK_KEY_d)) {
        IS_DARK_THEME = !IS_DARK_THEME; 
        set_theme(IS_DARK_THEME);
        return TRUE;
    }
    return FALSE;
}

void set_theme(gboolean enable) {
    GtkSettings *theme_settings = gtk_settings_get_default();
    g_object_set(theme_settings, "gtk-application-prefer-dark-theme", enable, NULL);
}

void save_at_quit_no(GtkWidget * window, gpointer user_data){
    g_application_quit(user_data);
}

void save_at_quit_yes(GtkWidget * window, gpointer user_data){
    quit_program_after_save = TRUE;
    save_buffer_to_file();
}
/******************************************************************************************* */
