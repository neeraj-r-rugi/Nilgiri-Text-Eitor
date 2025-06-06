#include "file_handling.h"
void load_file_into_buffer(){
    gchar *content = NULL;
    gsize length = 0;
    GError *error = NULL;
    if(access(file_path, F_OK) != 0){
        FILE * fp = fopen(file_path, "w");
        fclose(fp);
    }

    // Read the file content
    if (!g_file_get_contents(file_path, &content, &length, &error)) {
        g_printerr("Error reading file: %s\n", error->message);
        g_error_free(error);
        return;
    }

    // Set the text in the source buffer
    gtk_text_buffer_set_text(GTK_TEXT_BUFFER(buffer), content, length);

    g_free(content);
    
}


void save_buffer_to_file() {
    if(*no_cmd_arg != 1){
        GtkTextIter start, end;
        gchar *text;
        GError *error = NULL;
    
        // Get the full range of the buffer
        gtk_text_buffer_get_start_iter(GTK_TEXT_BUFFER(buffer), &start);
        gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(buffer), &end);
    
        // Get the text in the buffer
        text = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer), &start, &end, FALSE);
    
        // Write to file
        if (!g_file_set_contents(file_path, text, -1, &error)) {
            g_printerr("Error saving file: %s\n", error->message);
            g_error_free(error);
        } else {
            //Nothing For Future
        }
    
        g_free(text);
    }
}


