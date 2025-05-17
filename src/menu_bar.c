#include "menu_bar.h"
void menu_zoom_in(GtkWidget * call, gpointer window){
    editor_zoom_in(window);
}
void menu_zoom_out(GtkWidget * call, gpointer window){
    editor_zoom_out(window);
}
void menu_application_quit(GtkWidget * call, gpointer app){
    g_application_quit(app);
}
void menu_show_search_replace(GtkWidget * widget, gpointer user_data){
    if(gtk_widget_get_visible(search_replace_box) == FALSE){
        gtk_widget_show(search_replace_box);
    }else{
        gtk_widget_hide(search_replace_box);
        clear_highlights(buffer);
    }
}