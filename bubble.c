#include <stdio.h>
#include <stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include"bubble.h"
#include"q.h"
#include"show.h"




void BubbleSort(struct SeqQueue* q,WINDOW *win) {
    int n=q->tail-q->head+1;
    int swapped;
do{
    swapped=0; 
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (q->data[j]>q->data[j+1]) {
                int temp = q->data[j];
                q->data[j] = q->data[j + 1];
                q->data[j + 1] = temp;
                swapped = 1;  
                draw_bar_chart(q,win);  
                napms(1000); // 稍微暂停以便观察动画  
            }
        }}
    }while(swapped);
}
