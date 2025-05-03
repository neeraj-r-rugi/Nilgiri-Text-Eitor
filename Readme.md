# Nilgiri Text Editor
### What it is?
Nilgiri is simple lightweight text/code editor developed as a student project! It is written completely in C with **GNU TOOL KIT(GTK)** version-3.0, Which allows for _Cross-Platform_ support.
The Repository consists of all the files needed to compile the editor from scratch(cuz Installers are for NOOBS!) using the Makefile!

### Pre-requistes needed to compile the editor: 
You'll Need to install some _Framework's_ to compile the Text Editor and build it

Begin By installing the:

1. **_Mingw GCC Compiler_** if not alraedy present: `sudo apt install build-essential`, If you have a different compiler such as **Clang** thats also fine, but will have to use a different build system or update the current one.

    Note:  `sudo apt install build-essential` install's some other important and required packages such as _pkg-config_ required in the build system, if you ommit this you will have to update and rewrite the build system with custom compiler and linker flags. 

2. Install the following frameworks:
    * _GTK-3.0_ : `sudo apt instal libgtk-3-dev`
    * _GtkSourceView-3.0_: `sudo apt install libgtksourceview-3.0-dev`

    Note: If you are on windows(I am so sorry for you btw), This step is going to be quite Difficult. Refer this [file](./md_usr_hlp/Win_FrameWorks_hlp.md) to set up these frameworks on windows.


### How to get started?
1. Begin by Compiling the editor using the Makefile provided.
2. Enter the command: `make` or `mingw32-make`(On Some OS's such as Windows) in the termianl in this directorys context.
3. The Binary Executable will be produced and the editor is ready to use!

### Key Binds: 
1. **Zoom Keys**:
    * _'ctrl' + '='_ :  Zoom In
    * _'ctrl' + '-'_:   Zoom Out
2. **Close Editor**:
    * _'ctrl' + 'esc'_: Closes the editor.

