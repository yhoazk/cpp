/* conio is only for windows */
//#include <conio.h>
#include <ncurses.h>
#include <iostream>

int main(void)
{
    int t  = 0;
    initscr();
    printw("press 5 to end");
    refresh();
    while(t!=1)
    {
       if( getch() == 0x35)
       {
           t = 1;
       }
    }
    endwin();
    return 0;
}
