#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>



int main(void) {
    initscr();
    cbreak();
    noecho();

    if (has_colors() == FALSE) {
        endwin();
        printf("your terminal doesnt support color!");
        exit(1);    
    }

    int row, col;
    getmaxyx(stdscr, row, col);

    WINDOW *win = newwin(row, col, 0, 0);

    refresh();

    box(win, 0, 0);
    mvwprintw(win,  1, 1, "Hello World!");
    mvwvline(win, 1, col / 2, ACS_VLINE, row - 2);

    wrefresh(win);

    getch();

    endwin();
    return 0;
}
