/*
    Controls function, A,S,D and "Space"
*/

#include <stdio.h>
#include <ncurses.h>
#include <curses.h>



initscr();

mvwaddstr(stdscr, 1, 4, "Move the window");
mvwaddstr(stdscr, 2, 2, "with the arrow keys");
mvwaddstr(stdscr, 3, 6, "something");
mvwaddstr(stdscr, 5, 3, "Press 'q' to quit");

refresh();

while ((ch = getch()) != 'q') {
    switch (ch)
    {
        case KEY_UP:
            if (y>0)
            --y;
            break;
        case KEY_UP:
            if (y>0)
            --y;
            break;
        case KEY_UP:
            if (y>0)
            --y;
            break;
        case KEY_UP:
            if (y>0)
            --y;
            break;
    }
    refresh();
}
