#include "file_handling.h"
void load_file_into_buffer()
{
    gchar *content = NULL;
    gsize length = 0;
    GError *error = NULL;
    if (access(file_path, F_OK) != 0)
    {
        FILE *fp = fopen(file_path, "w");
        fclose(fp);
    }

    // Read the file content
    if (!g_file_get_contents(file_path, &content, &length, &error))
    {
        g_printerr("Error reading file: %s\n", error->message);
        g_error_free(error);
        return;
    }

    set_file_language();

    // Set the text in the source buffer
    gtk_text_buffer_set_text(GTK_TEXT_BUFFER(buffer), content, length);

    g_free(content);
}

void save_buffer_to_file()
{
    const gchar *entry = NULL;
    if (strcmp(file_path, "") != 0)
    {
        GtkTextIter start, end;
        gchar *text;
        GError *error = NULL;

        // Get the full range of the buffer
        gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer), &start);
        gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(buffer), &end);

        // Get the text in the buffer
        text = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer), &start, &end, FALSE);

        // Write to file
        if (!g_file_set_contents(file_path, text, -1, &error))
        {
            g_printerr("Error saving file: %s\n", error->message);
            g_error_free(error);
        }
        else
        {
            // Nothing For Future
        }
        g_free(text);
        buffer_has_changed = FALSE;
        show_file_saved_overlay();
    }
    else
    {
        gtk_widget_hide(save_at_quit_popup);
        gtk_widget_show(new_file_saved_popup);
        gtk_widget_set_sensitive(GTK_WIDGET(text_area), FALSE);
        gtk_widget_grab_focus(new_file_saved_enrty);
        entry = gtk_entry_get_text(GTK_ENTRY(new_file_saved_enrty));
        if (g_strcmp0(entry, "~") == 0)
        {
            gtk_widget_hide(new_file_saved_popup);
            gtk_widget_set_sensitive(GTK_WIDGET(text_area), TRUE);
            gtk_entry_set_text(GTK_ENTRY(new_file_saved_enrty), "");
            buffer_has_changed = FALSE;
        }else if(g_strcmp0(entry, "~") != 0 && g_strcmp0(entry, "") != 0){
            strncpy(file_path, entry, sizeof(file_path)-1);
            file_path[sizeof(file_path) - 1] = '\0';
            FILE * fp = fopen(file_path, "w");
            fclose(fp);
            gtk_widget_hide(new_file_saved_popup);
            gtk_widget_set_sensitive(GTK_WIDGET(text_area), TRUE);
            gtk_entry_set_text(GTK_ENTRY(new_file_saved_enrty), "");
            save_buffer_to_file();
        }
    }
}

void to_save_at_quit(){
    gtk_widget_show(save_at_quit_popup);
    gtk_widget_set_sensitive(GTK_WIDGET(text_area), FALSE);
}
