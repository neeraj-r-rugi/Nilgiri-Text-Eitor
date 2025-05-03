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

// Global Variables
GtkWidget *zoom_popup = NULL;
GtkWidget *search_replace_box = 0;

// A structure that holds buffer data
typedef struct
{
    GtkSourceBuffer *buffer;
    GtkEntry *search_entry;
    GtkEntry *replace_entry;
    GtkTextIter last_match_end;
    gboolean has_match;
} SearchData;

/*********************************************************************************************** */
// Definitions of search and replace elements
static GtkTextTag *ensure_search_tag(GtkTextBuffer *buffer)
{
    GtkTextTagTable *tag_table = gtk_text_buffer_get_tag_table(buffer);
    GtkTextTag *tag = gtk_text_tag_table_lookup(tag_table, "search-tag");
    if (!tag)
    {
        tag = gtk_text_tag_new("search-tag");
        g_object_set(tag, "background", "#bbdefb","foreground", "#000000", NULL);
        gtk_text_tag_table_add(tag_table, tag);
    }
    return tag;
}

static void clear_highlights(GtkSourceBuffer *buffer)
{
    GtkTextIter start, end;
    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer), &start);
    gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(buffer), &end);
    gtk_text_buffer_remove_tag_by_name(GTK_TEXT_BUFFER(buffer), "search-tag", &start, &end);
}

static void on_search_changed(GtkEntry *entry, gpointer user_data)
{
    SearchData *data = user_data;
    GtkSourceBuffer *buffer = data->buffer;
    const gchar *search_text = gtk_entry_get_text(data->search_entry);

    clear_highlights(buffer);

    if (strlen(search_text) == 0)
        return;

    GtkTextIter start, match_start, match_end;
    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer), &start);

    GtkTextTag *tag = ensure_search_tag(GTK_TEXT_BUFFER(buffer));

    while (gtk_text_iter_forward_search(&start, search_text, GTK_TEXT_SEARCH_CASE_INSENSITIVE,
                                        &match_start, &match_end, NULL))
    {
        gtk_text_buffer_apply_tag(GTK_TEXT_BUFFER(buffer), tag, &match_start, &match_end);
        start = match_end;
    }

    // Reset match state
    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer), &data->last_match_end);
    data->has_match = FALSE;
}

static void on_replace_next_clicked(GtkButton *button, gpointer user_data)
{
    SearchData *data = user_data;
    GtkSourceBuffer *buffer = data->buffer;
    const gchar *search_text = gtk_entry_get_text(data->search_entry);
    const gchar *replace_text = gtk_entry_get_text(data->replace_entry);

    if (strlen(search_text) == 0)
        return;

    GtkTextIter match_start, match_end;
    if (!gtk_text_iter_forward_search(&data->last_match_end, search_text,
                                      GTK_TEXT_SEARCH_CASE_INSENSITIVE, &match_start, &match_end, NULL))
    {
        // Restart from beginning
        gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer), &match_start);
        if (!gtk_text_iter_forward_search(&match_start, search_text,
                                          GTK_TEXT_SEARCH_CASE_INSENSITIVE, &match_start, &match_end, NULL))
            return; // no match
    }

    gtk_text_buffer_delete(GTK_TEXT_BUFFER(buffer), &match_start, &match_end);
    gtk_text_buffer_insert(GTK_TEXT_BUFFER(buffer), &match_start, replace_text, -1);

    // Update search position
    data->last_match_end = match_start;
    data->has_match = TRUE;

    // Reapply highlights
    on_search_changed(GTK_ENTRY(data->search_entry), data);
}

static void on_replace_all_clicked(GtkButton *button, gpointer user_data)
{
    SearchData *data = user_data;
    GtkSourceBuffer *buffer = data->buffer;
    const gchar *search_text = gtk_entry_get_text(data->search_entry);
    const gchar *replace_text = gtk_entry_get_text(data->replace_entry);

    if (strlen(search_text) == 0)
        return;

    GtkTextIter start, match_start, match_end;
    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer), &start);

    while (gtk_text_iter_forward_search(&start, search_text,
                                        GTK_TEXT_SEARCH_CASE_INSENSITIVE, &match_start, &match_end, NULL))
    {
        gtk_text_buffer_delete(GTK_TEXT_BUFFER(buffer), &match_start, &match_end);
        gtk_text_buffer_insert(GTK_TEXT_BUFFER(buffer), &match_start, replace_text, -1);

        // Continue searching after replaced text
        start = match_start;
    }

    // Reapply highlights
    on_search_changed(GTK_ENTRY(data->search_entry), data);
}
/*********************************************************************************************** */

static void load_css_for_wideget(GtkWidget *widget, const char *file_path)
{
    GtkCssProvider *provider = gtk_css_provider_new();
    GError *error = NULL;
    if (!gtk_css_provider_load_from_path(provider, file_path, &error))
    {
        g_warning("Failed to load CSS file: %s", error->message);
        g_clear_error(&error);
    }
    GtkStyleContext *context = gtk_widget_get_style_context(widget);
    gtk_style_context_add_provider(context,
                                   GTK_STYLE_PROVIDER(provider),
                                   GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    g_object_unref(provider);
}

static void init_zoom_overlay(GtkWidget **zoom, GtkWidget *overlay)
{
    GtkCssProvider *provider = gtk_css_provider_new();
    *zoom = gtk_label_new("");
    gtk_widget_set_halign(*zoom, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(*zoom, GTK_ALIGN_CENTER);
    gtk_widget_set_margin_bottom(*zoom, 10);
    gtk_widget_set_margin_top(*zoom, 10);
    gtk_widget_set_margin_end(*zoom, 10);
    gtk_widget_set_name(*zoom, "zoom-popup");   // Set Name For CSS
    load_css_for_wideget(*zoom, CSS_FILE_PATH); // Call CSS Styling for widget
    gtk_overlay_add_overlay(GTK_OVERLAY(overlay), *zoom);
}

static void activate(GtkApplication *app, gpointer user_data)
{
    // Window and Overlay Declarations
    GtkWidget *window; //*Declaring the Editor window
    GtkWidget *replace_next_btn, *replace_all_btn, *scrolled_window,
        *text_view, *hbox, *entry_box, *search_entry, *replace_entry; // Widgets Pertaining to search and replace
    GtkWidget *scrollable_window;                                     //* Makes the current window in context scrollable
    GtkWidget *master_overlay;                                        // Declaration for the overlay when the user Zooms the font;
    GtkSourceView *text_area;                                         //*From GtkSourceView, Implenets a Screen wide textfield (Where all the text can be editied)
    GtkSourceBuffer *buffer;                                          //*Implements the text Buffer for GtkSourceView
    GdkEventKey *key_event;                                           //! This hasn't been used anywhere, check validity of this declarartion.

    // Overlay Intialisation
    master_overlay = gtk_overlay_new();

    // Create window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Nilgiri Text Editor");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    // Search and Replace Box and widgets
    search_replace_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    entry_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    search_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(search_entry), "Search...");
    replace_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(replace_entry), "Replace with...");
    replace_next_btn = gtk_button_new_with_label("Replace Next");
    replace_all_btn = gtk_button_new_with_label("Replace All");
    gtk_box_pack_start(GTK_BOX(entry_box), search_entry, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(entry_box), replace_entry, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(entry_box), replace_next_btn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(entry_box), replace_all_btn, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(search_replace_box), entry_box, FALSE, FALSE, 0);

    // Make window scrollable
    scrollable_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrollable_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    // Add Text Editor(GtkSourceView) to scrolable window
    buffer = gtk_source_buffer_new(NULL);
    text_area = GTK_SOURCE_VIEW(gtk_source_view_new_with_buffer(buffer));
    gtk_source_view_set_show_line_numbers(text_area, TRUE); // Adds Line Number to Text Editor
    gtk_source_view_set_auto_indent(text_area, TRUE);    // Adds Auto Indent in the text Editor

    // Text Data for Search and Replace
    SearchData *data = g_new0(SearchData, 1);
    data->buffer = buffer;
    data->search_entry = GTK_ENTRY(search_entry);
    data->replace_entry = GTK_ENTRY(replace_entry);
    gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer), &data->last_match_end);
    data->has_match = FALSE;

    // Checking for Key Events
    g_signal_connect(window, "key-press-event", G_CALLBACK(zoom_key_pressed), NULL);
    g_signal_connect(window, "key-press-event", G_CALLBACK(quit_key_pressed), app);
    g_signal_connect(window, "key-press-event", G_CALLBACK(toggle_dark_theme), NULL);
    g_signal_connect(window, "key-press-event", G_CALLBACK(show_search_replace_box), NULL);
    g_signal_connect(search_entry, "changed", G_CALLBACK(on_search_changed), data);
    g_signal_connect(replace_next_btn, "clicked", G_CALLBACK(on_replace_next_clicked), data);
    g_signal_connect(replace_all_btn, "clicked", G_CALLBACK(on_replace_all_clicked), data);

    // Adding Containers
    gtk_container_add(GTK_CONTAINER(scrollable_window), GTK_WIDGET(text_area));
    gtk_container_add(GTK_CONTAINER(master_overlay), scrollable_window);
    gtk_container_add(GTK_CONTAINER(window), master_overlay);

    // Initialise Zoom overlay
    init_zoom_overlay(&zoom_popup, master_overlay);

    // Adding Search Replace Overlay
    gtk_overlay_add_overlay(GTK_OVERLAY(master_overlay), search_replace_box);
    gtk_widget_set_halign(search_replace_box, GTK_ALIGN_END);
    gtk_widget_set_valign(search_replace_box, GTK_ALIGN_START);
    gtk_widget_set_name(search_replace_box, "search-replace"); 
    load_css_for_wideget(search_replace_box, CSS_FILE_PATH);
    gtk_widget_set_margin_start(search_replace_box, 10);
    gtk_widget_set_margin_top(search_replace_box, 10);
    gtk_widget_set_can_focus(search_entry, TRUE);
    gtk_widget_set_can_focus(replace_entry, TRUE);
    gtk_widget_set_can_focus(GTK_WIDGET(text_area), TRUE);

    // Dispaly All Required UI Initially
    gtk_widget_show_all(window);

    // UI that does not need to be shown at start
    gtk_widget_hide(zoom_popup);
    gtk_widget_hide(search_replace_box);
    // g_free(data);
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.nilgiri.texteditor", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}