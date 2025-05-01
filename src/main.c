#include "defines.h"
/*
    @author: Neeraj R Rugi
    @category: Code/Text Editor
    @brief: A simple GUI based Text Editor using the GNU TOOL KIT
    @details:
        -> Frameworks used:
            -> GTK-3.0
            -> GTKSourceView - 3.0
        -> Developed Primarily for Linux Operating Systems using GNOME
    @attention:
        -> Comments bearing "!External Requirement" indicate header files not present in the standard C Library

*/
static void temp(){}//A temporary function that serves no purpose.


static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;  //*Declaring the Editor window
    GtkWidget *scrollable_window;//* Makes the current window in context scrollable
    GtkSourceView *text_area;//*From GtkSourceView, Implenets a Screen wide textfield (Where all the text can be editied)
    GtkSourceBuffer *buffer;//*Implements the text Buffer for GtkSourceView
    GdkEventKey *key_event;//!This hasn't been used anywhere, check validity of this declarartion.


    //Create window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Nilgiri Text Editor");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    
    //Make window scrollable
    scrollable_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(scrollable_window));
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollable_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    
    //Add Text Editor(GtkSourceView) to scrolable window
    buffer = gtk_source_buffer_new(NULL);
    text_area = GTK_SOURCE_VIEW(gtk_source_view_new_with_buffer(buffer));
    gtk_source_view_set_show_line_numbers(text_area, TRUE);//Adds Line Number to Text Editor
    gtk_source_view_set_auto_indent(text_area, TRUE);//Adds Auto Indent to text Editor
    gtk_container_add(GTK_CONTAINER(scrollable_window), GTK_WIDGET(text_area));
    //gtk_container_add(GTK_CONTAINER(window), scrollable_window);
    
    //Checking for Key Events
    g_signal_connect(window, "key-press-event", G_CALLBACK(zoom_key_pressed), NULL);
    

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.nilgiri.texteditor", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}