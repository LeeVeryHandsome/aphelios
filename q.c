#include <stdio.h>
#include <stdlib.h>
#include<ncurses.h>
#include<unistd.h>
#include<time.h>
#include"bubble.h"
#include"q.h"
#include"show.h"

#define SeqQueueMaxSize 1000

typedef int SeqQueueType;


// 队列的初始化
void SeqQueueInit(SeqQueue* q) {
    if (q == NULL) return;
    q->size = 0;
    q->head = 0;
    q->tail = 0;
}

// 入队列
void SeqQueuePush(SeqQueue* q, SeqQueueType value) {
    if (q == NULL) return;
    if (q->size >= SeqQueueMaxSize) return; // 队列已满
    q->data[q->tail++] = value;
    q->tail %= SeqQueueMaxSize; // 环形队列
    ++q->size;
}

// 出队列
void SeqQueuePop(SeqQueue* q) {
    if (q == NULL) return;
    if (q->size == 0) return; // 队列为空
    ++q->head;
    q->head %= SeqQueueMaxSize; // 环形队列
    --q->size;
}

// 取队首元素
SeqQueueType SeqQueueFront(SeqQueue* q) {
    if (q == NULL || q->size == 0) return -1; // 队列为空
    return q->data[q->head];
}


