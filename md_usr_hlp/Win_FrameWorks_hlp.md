# Installing GTK-3.0 and GtkSourceView on Windows:

## Prerequisites
- Windows 7 or later (64-bit recommended)
- Administrator privileges
- Basic familiarity with command line

## Method 1: Using MSYS2 (Recommended)

### Step 1: Install MSYS2
1. Download MSYS2 from [https://www.msys2.org/](https://www.msys2.org/)
2. Run the installer and follow the default options
3. After installation, launch "MSYS2 MSYS" from the Start Menu

### Step 2: Update MSYS2 Packages
In the MSYS2 terminal, run:
```bash
pacman -Syu
```
If the terminal closes during update, reopen it and run:
```bash
pacman -Su
```

### Step 3: Install GTK3 and GtkSourceView
For 64-bit development:
```bash
pacman -S mingw-w64-x86_64-gtk3 mingw-w64-x86_64-gtksourceview3
```

For 32-bit development:
```bash
pacman -S mingw-w64-i686-gtk3 mingw-w64-i686-gtksourceview3
```

### Step 4: Verify Installation
Create a test file `test.c`:
```c
#include <gtk/gtk.h>
#include <gtksourceview/gtksource.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK3 Test");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    GtkSourceBuffer *buffer = gtk_source_buffer_new(NULL);
    GtkWidget *view = gtk_source_view_new_with_buffer(buffer);
    gtk_container_add(GTK_CONTAINER(window), view);
    
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
```

Compile with:
```bash
gcc test.c -o test.exe `pkg-config --cflags --libs gtk+-3.0 gtksourceview-3.0`
```

Run with:
```bash
./test.exe
```

## Method 2: Direct Installation (Without MSYS2)

### Step 1: Download GTK3 SDK
1. Go to [https://www.gtk.org/download/windows.php](https://www.gtk.org/download/windows.php)
2. Download the 64-bit or 32-bit bundle (e.g., gtk3-runtime-3.24.XX-202X-XX-XX-ts-win64.exe)

### Step 2: Install GTK3 Runtime
1. Run the installer
2. Choose "Install for all users" if you have admin rights
3. Note the installation directory (typically `C:\gtk`)

### Step 3: Download GtkSourceView
1. Get the latest GtkSourceView from [https://github.com/GNOME/gtksourceview](https://github.com/GNOME/gtksourceview)
2. Download the pre-built binaries or build from source

### Step 4: Set Up Environment Variables
1. Open System Properties > Advanced > Environment Variables
2. Add to PATH: `C:\gtk\bin`
3. Create new variable `PKG_CONFIG_PATH` with value `C:\gtk\lib\pkgconfig`

### Step 5: Verify Installation
Open Command Prompt and check:
```cmd
pkg-config --modversion gtk+-3.0
pkg-config --modversion gtksourceview-3.0
```

## Development Setup

### For Visual Studio
1. Create a new C++ project
2. In Project Properties:
   - C/C++ > Additional Include Directories: Add `C:\gtk\include\gtk-3.0`, `C:\gtk\include\glib-2.0`, `C:\gtk\lib\glib-2.0\include`
   - Linker > Additional Library Directories: Add `C:\gtk\lib`
   - Linker > Input: Add `gtk-3.lib`, `gdk-3.lib`, `gtksourceview-3.lib`

### For Code::Blocks
1. Create a new project
2. Go to Project Build Options
3. Add `C:\gtk\include\gtk-3.0` etc. to compiler search directories
4. Add `C:\gtk\lib` to linker search directories
5. Add the required libraries to linker settings

## Troubleshooting

1. **Missing DLL errors**:
   - Ensure `C:\gtk\bin` is in your PATH
   - Copy required DLLs to your executable directory

2. **Pkg-config not found**:
   - Install pkg-config for Windows or use absolute paths

3. **Theme not applied**:
   - Set the environment variable: `GTK_THEME=Windows-10`

4. **GtkSourceView not found**:
   - Verify the files are in `C:\gtk\lib\gtksourceview-3.0`
   - Check `PKG_CONFIG_PATH` includes the correct directory
