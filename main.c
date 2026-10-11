#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "draw.h"



int main(void) {
    initscr();
    cbreak();
    noecho();

    draw_rectangle(20, 50, 0, 5);

    return 0;
}
