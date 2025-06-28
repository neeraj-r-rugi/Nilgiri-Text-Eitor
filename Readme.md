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
1. Begin by Compiling the editor using the Makefile provided, `If you are on a Linux, then the pre-compiled binary is already provided, you can skip this and the next 2 steps`.
2. Enter the command: `make` or `mingw32-make`(On Some OS's such as Windows) in the termianl in this directorys context.
3. The Binary Executable will be produced and the editor is ready to use!
4. The editor can perform multiple actions, depending on how it is invoked:
    * Double click the executable: Opens a new file without any content, file can be saved to create a new file.
    * Use the command line to open a file with editor:
        * Type: _./Nilgiri.out <filename or filepath>_, Opens the currently existing file, If no file is found in that path a new file is created with the same name. 
        `NOTE`: Care should be take that the terminal's directory context is in the same file as that of the binary, or add the binary to PATH/System Envoirment to invoke it in any directory, or replcae _./Nilgiri.out_ with the actual file path of where the `Nilgiri.out` binary is. 
5. It is best intended to use the `file ribbon's quit button` or `quit key bind` as GUI cross for closing the file is a hard close that does not check is the file is to be saved.

### Key Binds: 
1. **Zoom Keys**:
    * _'ctrl' + '='_ :  Zoom In.
    * _'ctrl' + '-'_:   Zoom Out.
2. **Close Editor**:
    * _'ctrl' + 'esc'_: Closes the editor.
3. **Save File**:
    * _'ctrl' + 's'_: Saves the file.
4. **Toggle Highlighting**:
    * _'ctrl' + 'H'_: Toggles highlighting the text.
5. **Search and Replace**:
    * _'ctrl' + 'F'_: Opens search-replace box, can be closed by the same keybind. 
5. **Toggle Theme**:
    * _'ctrl' + 'D'_: Toggles between Light and Dark theme(If you have your system Settings set to dark mode, It will not be overridden hence dark mode cannot be toggled)

### Screenshots of the text editor.
1. Example of terminal commands:
    * [](./md_usr_hlp/images/1.png)
2. Blank Window of text editor:
    * [](./md_usr_hlp/images/2.png)
3. Example of Light mode:
    * [](./md_usr_hlp/images/3.png)
4. Saving File:
    * [](./md_usr_hlp/images/4.png)
5. Search Replace:
    * [](./md_usr_hlp/images/5.png)
    * [](./md_usr_hlp/images/6.png)
6. Exit without saving warning:
    * [](./md_usr_hlp/images/7.png)



