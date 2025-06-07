#ifndef OVERLAYS_H
#define OVERLAYS_H
#include "defines.h"

//Variable Declaration
//extern GtkWidget *zoom_popup;

/******************************************************************* */
//Function Prototype

void show_zoom_overlay();
void show_file_saved_overlay();
static gboolean hide_zoom_popup_cb();
static void hide_zoom_popup();
static void hide_file_saved_popup();
static gboolean hide_file_saved_popup_cb();
/******************************************************************* */

#endif