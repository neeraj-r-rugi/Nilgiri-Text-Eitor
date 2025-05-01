#ifndef FONTS_H
#define FONTS_H
#include "defines.h"

//Function Prototypes
void editor_apply_font_size(GtkWidget*, short int);//Applies the font size to texteditor
void editor_zoom_in(GtkWidget*);//Increments font size by one
void editor_zoom_out(GtkWidget*);//Decrements font size by one

#endif