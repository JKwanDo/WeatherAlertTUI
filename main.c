#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>



int main(void) {
    initscr();
    cbreak();
    noecho();

    int row, col;
    getmaxyx(stdscr, row, col);

    WINDOW *win = newwin(row, col, 0, 0);

    refresh();

    box(win, 0, 0);

    wrefresh(win);

    getch();

    endwin();
    return 0;
}
