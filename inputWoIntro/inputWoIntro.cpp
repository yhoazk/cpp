/* conio is only for windows */
#define IS_WINDOWS
#ifdef IS_WINDOWS
#include <conio.h>
#else
#include <ncurses.h>
#endif

# if 0
Methods for conio.h

Member functions
kbhit - Determines if a keyboard key was pressed.
gcgets - Reads a string directly from the console.
cscanf - Reads formatted values directly from the console.
putch - Writes a character directly to the console.
cputs - Writes a string directly to the console.
cprintf - Formats values and writes them directly to the console.
clrscr - Clears the screen.
getch - Get char entry from the console
#endif

#include <iostream>

int main(void)
{
    int t  = 0;
    #ifdef IS_WINDOWS
    clrscr();
    cputs("press 5 to end");
    #else
    initscr();
    printw("press 5 to end");
    refresh();
    #endif
    while(t!=1)
    {
       if( getch() == 0x35)
       {
           t = 1;
       }
    }
    #ifndef IS_WINDOWS
    endwin();
    #endif
    return 0;
}
