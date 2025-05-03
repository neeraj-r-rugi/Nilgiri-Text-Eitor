#ifndef MAIN_H
#define MAIN_H
#include "defines.h"

//Variable Declaration
extern GtkWidget* zoom_popup;//The Label pointer to be displayed when Zooming

//Function Prototype
/*------------------------------------------------------------------------------*/
/*
    @brief: Intialises the GTK windows and contains declarations for all the widgets
    @param: The GTK application
    @param: Pointer Data 
*/
static void activate(GtkApplication *, gpointer);
/*
    @brief: Intialises the Zoom Overlay, to be used whenever the user Zooms
    @param: The Pointer of the GTK Label that displays the Zoom Text
    @param: The Zoom Overlay
*/
static void init_zoom_overlay(GtkWidget ** , GtkWidget *);
/*
    @brief: Loads the CSS data for the parsed object
    @param: TThe Widget whose Style is to applied
    @param: The Path where The CSS file is
*/
static void load_css_for_wideget(GtkWidget *, const char *);
/*------------------------------------------------------------------------------*/
#endif