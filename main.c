#include <stdio.h>
#include <stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include"bubble.h"
#include"q.h"
#include"show.h"


 
#define WINDOW_HEIGHT 30  
#define WINDOW_WIDTH 40
  
int main() {
    SeqQueue q;
    SeqQueueInit(&q);


    srand(time(NULL));
    for (int i = 1; i <= 10; ++i) {
        SeqQueuePush(&q, rand()%21);//20以内的随机数
    }


 
    WINDOW *win;  
  
    // Initialize ncurses  
    initscr();  
    cbreak();  
    noecho();  
    keypad(stdscr, TRUE);  
    nodelay(stdscr, TRUE);  
  
    // Create a new window  
    win = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);  
    wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');  
    wrefresh(win);  
  

    draw_bar_chart(&q, win);  
  
    // Perform bubble sort with visualization  
    BubbleSort(&q,win);  
  
    // Wait for a key press to exit  
    getch();  
  
    // Cleanup and exit  
    delwin(win);  
    endwin();  
  
    return 0;  
}
