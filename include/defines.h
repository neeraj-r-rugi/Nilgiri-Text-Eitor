#ifndef DEFINES_H
#define DEFINES_H
/********************************************************************* */
/*
    @about: Consists of header declarations for the programs
*/

//External and System Header Inclusion
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>
#include<gtk/gtk.h> //!External Requirement
#include<gtksourceview/gtksource.h>//!!External Requirement

#if defined(_WIN32)
    #include <windows.h>
    #include <wchar.h>
    #include <shlwapi.h>
#elif defined(__APPLE__)
    #include <mach-o/dyld.h>
    #include <libgen.h>
    #include <limits.h>
#else
    #include <unistd.h>
    #include <libgen.h>
    #include <limits.h>
#endif


#define PATH_MAX 4096

//Internal Header Inclusion
#include "file_handling.h"
#include "main.h"
#include "fonts.h"
#include "process.h"
#include "overlays.h"
#include "menu_bar.h"
/********************************************************************* */

/********************************************************************* */
//MACROS FOR THE PROGRAM

extern char * CSS_FILE_PATH;

/********************************************************************* */


/********************************************************************* */
/*
    @about: All global Variable Declarations done here 

*/
extern const short int DEFAULT_FONT_SIZE;//Declares the intial font size to be set
extern short int CURRENT_FONT_SIZE;//Updated Font Size
extern gboolean IS_DARK_THEME;//Toggles weather Dark Theme Should be enabled or Not.
extern gboolean buffer_has_changed;
extern gboolean quit_program_after_save;
extern gboolean show_text_highlighting;


//Functions
void update_buufer_has_changed();
/********************************************************************* */
#endif