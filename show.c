#include <stdio.h>
#include <stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include"bubble.h"
#include"q.h"
#include"show.h"
#define ARRAY_SIZE 10  
#define WINDOW_HEIGHT 30  
#define WINDOW_WIDTH 40  
#define BAR_WIDTH 2  



void draw_bar_chart(struct SeqQueue *q, WINDOW *win) {  
    int max_val = 0;  
    for (int i = 0; i < q->size; i++) {  
        if (q->data[i] > max_val) {  
            max_val = q->data[i];  
        }  
    }  
  
    int scale_factor = (WINDOW_HEIGHT - 4) / max_val; // 减去顶部和底部的边界  
  
    wclear(win);  
    box(win, 0, 0);  
  
    for (int i = 0; i < q->size; i++) {  
        int start_y = WINDOW_HEIGHT - 3 - (q->data[i] * scale_factor);  
        int height = q->data[i] * scale_factor;  
   
        for (int y = start_y; y < WINDOW_HEIGHT - 3; y++) {  
            if (y >= start_y && y < start_y + height) {  
                for (int x = 3 + (i * (BAR_WIDTH + 1)); x < 2 + ((i + 1) * (BAR_WIDTH + 1)); x++) {  
                    mvwaddch(win, y, x, '#'); 
                  
                }  
            }  
        }  
    }  
  
  
    for (int i = 0; i < q->size; i++) {  
        mvwprintw(win, WINDOW_HEIGHT - 2, 3 + (i * (BAR_WIDTH + 1)) - BAR_WIDTH / 2, " %d", q->data[i]);  
    }  
  
    wrefresh(win);  
}  
