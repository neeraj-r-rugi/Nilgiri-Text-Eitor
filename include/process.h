#ifndef PROCESS_H
#define PROCESS_H
#include "defines.h"

//Function Prototype


gboolean zoom_key_pressed(GtkWidget*, GdkEventKey*);//*Function Checks if the valid keys to alter font size have been pressed.
gboolean quit_key_pressed(GtkWidget *, GdkEventKey *, gpointer );//*Function Checks if the valid keys to quit the program have been pressed.

#endif