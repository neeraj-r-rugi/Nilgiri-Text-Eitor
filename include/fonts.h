/*
Nilgiri Text Editor: A simple lightweight text/code editor developed as a student project!  
Copyright (C) 2024 NEERAJ R RUGI

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef FONTS_H
#define FONTS_H
#include "defines.h"

//Function Prototypes
void editor_apply_font_size(GtkWidget*, short int);//Applies the font size to texteditor
void editor_zoom_in(GtkWidget*);//Increments font size by one
void editor_zoom_out(GtkWidget*);//Decrements font size by one

#endif