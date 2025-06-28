#ifndef PROCESS_H
#define PROCESS_H
#include "defines.h"

//Function Prototype


/*
    !!
    @brief: UPDATE
    @param: UPDATE
    @param: UPDATE
*/
gboolean zoom_key_pressed(GtkWidget*, GdkEventKey*);
/*
    !!
    @brief: UPDATE
    @param: UPDATE
    @param: UPDATE
*/
gboolean quit_key_pressed(GtkWidget *, GdkEventKey *, gpointer );
/*
    !!
    @brief: UPDATE
    @param: UPDATE
    @param: UPDATE
*/
gboolean toggle_dark_theme(GtkWidget*, GdkEventKey*);
/*
    !!
    @brief: UPDATE
    @param: UPDATE
    @param: UPDATE
*/
void set_theme(gboolean);
/*
    !!
    @brief: UPDATE
    @param: UPDATE
    @param: UPDATE
*/
gboolean search_key_pressed(GtkWidget * , GdkEventKey * , gpointer );
/*
    !!
    @brief: UPDATE
    @param: UPDATE
    @param: UPDATE
*/
gboolean show_search_replace_box(GtkWidget * , GdkEventKey * , gpointer );

gboolean highlight_key_pressed(GtkWidget * , GdkEventKey * , gpointer );


gboolean save_key_pressed(GtkWidget* , GdkEventKey* );

void save_at_quit_no(GtkWidget * , gpointer );

void save_at_quit_yes(GtkWidget * , gpointer );

void set_file_language();

void unset_file_language();

char * get_css_file_path(); 

#endif