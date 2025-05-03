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

//Global Variables
GtkWidget *zoom_popup = NULL;

//A temporary function that serves no purpose.
static void temp(){}

static void load_css_for_wideget(GtkWidget * widget, const char * file_path){
    GtkCssProvider *provider = gtk_css_provider_new();
    GError *error = NULL;
    if (!gtk_css_provider_load_from_path(provider, file_path, &error)) {
        g_warning("Failed to load CSS file: %s", error->message);
        g_clear_error(&error);
    }
    GtkStyleContext *context = gtk_widget_get_style_context(widget);
    gtk_style_context_add_provider(context,
        GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    g_object_unref(provider);

}

static void init_zoom_overlay(GtkWidget ** zoom, GtkWidget * overlay){
    GtkCssProvider *provider = gtk_css_provider_new();
    *zoom = gtk_label_new("");
    gtk_widget_set_halign(*zoom, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(*zoom, GTK_ALIGN_CENTER);
    gtk_widget_set_margin_bottom(*zoom, 10);
    gtk_widget_set_margin_top(*zoom, 10);
    gtk_widget_set_margin_end(*zoom,10);
    gtk_widget_set_name(*zoom, "zoom-popup");//Set Name For CSS
    load_css_for_wideget(*zoom, CSS_FILE_PATH);// Call CSS Styling for widget
    gtk_overlay_add_overlay(GTK_OVERLAY(overlay), *zoom);

}   

static void activate(GtkApplication * app, gpointer user_data) {
    //
    GtkWidget *window;  //*Declaring the Editor window
    GtkWidget *scrollable_window;//* Makes the current window in context scrollable
    GtkWidget *master_overlay; //Declaration for the overlay when the user Zooms the font;
    GtkSourceView *text_area;//*From GtkSourceView, Implenets a Screen wide textfield (Where all the text can be editied)
    GtkSourceBuffer *buffer;//*Implements the text Buffer for GtkSourceView
    GdkEventKey *key_event;//!This hasn't been used anywhere, check validity of this declarartion.

    //Overlay Intialisation
    master_overlay = gtk_overlay_new();

    //Create window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Nilgiri Text Editor");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    
    //Make window scrollable
    scrollable_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollable_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    
    //Add Text Editor(GtkSourceView) to scrolable window
    buffer = gtk_source_buffer_new(NULL);
    text_area = GTK_SOURCE_VIEW(gtk_source_view_new_with_buffer(buffer));
    gtk_source_view_set_show_line_numbers(text_area, TRUE);//Adds Line Number to Text Editor
    gtk_source_view_set_auto_indent(text_area, TRUE);//Adds Auto Indent to text Editor
    
    //Checking for Key Events
    g_signal_connect(window, "key-press-event", G_CALLBACK(zoom_key_pressed), NULL);
    g_signal_connect(window, "key-press-event", G_CALLBACK(quit_key_pressed), app);

    //Adding Containers
    gtk_container_add(GTK_CONTAINER(scrollable_window), GTK_WIDGET(text_area));
    gtk_container_add(GTK_CONTAINER(master_overlay), scrollable_window);
    gtk_container_add(GTK_CONTAINER(window), master_overlay);

    //Initialise Zoom overlay
    init_zoom_overlay(&zoom_popup, master_overlay);



    //Dispaly All Required UI Initially 
    gtk_widget_show_all(window);

    //UI that does not need to be shown at start
    gtk_widget_hide(zoom_popup);
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