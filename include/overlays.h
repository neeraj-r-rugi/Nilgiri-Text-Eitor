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