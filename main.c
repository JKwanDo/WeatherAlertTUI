#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>



int main(void) {
    initscr();
    cbreak();
    noecho();
    curs_set(0);


    if (has_colors() == FALSE) {
        endwin();
        printf("your terminal doesnt support color!");
        exit(1);    
    }
    start_color();

    init_pair(1, COLOR_CYAN, COLOR_RED);

    int row, col;
    getmaxyx(stdscr, row, col);

    WINDOW *win = newwin(row, col, 0, 0);
    keypad(win, TRUE);

    int ch;
    while (1) {
        wclear(win);

        box(win, 0, 0);
        wattron(win, COLOR_PAIR(1));
        mvwprintw(win,  1, 1, "Hello World!");
        wattroff(win, COLOR_PAIR(1));
        mvwvline(win, 1, col / 2, ACS_VLINE, row - 2);

        wrefresh(win);

        getch();

        ch = wgetch(win);

        if (ch == KEY_RESIZE) {
            endwin();
            refresh();
            getmaxyx(stdscr, row, col);

            wresize(win, row, col);
            mvwin(win, 0, 0);
        }
        else {
            break;
        }
    }

    
    return 0;
}
