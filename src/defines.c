#include "defines.h"


//Global Variable Intialisations
const short int DEFAULT_FONT_SIZE = 12;
short int CURRENT_FONT_SIZE = DEFAULT_FONT_SIZE;
gboolean IS_DARK_THEME = FALSE;
gboolean buffer_has_changed = FALSE;
gboolean quit_program_after_save = FALSE;
gboolean show_text_highlighting = TRUE;


//Functions
/****************************************************************************** */
void update_buufer_has_changed(){
    buffer_has_changed = TRUE;
}

/****************************************************************************** */