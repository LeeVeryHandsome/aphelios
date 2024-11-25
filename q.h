#ifndef QUEUE_H
#define QUEUE_H
 
#define SeqQueueMaxSize 1000

typedef int SeqQueueType;

typedef struct SeqQueue {
    SeqQueueType data[SeqQueueMaxSize];
    size_t head;
    size_t tail;
    size_t size;
} SeqQueue;
SeqQueueType SeqQueueFront(SeqQueue* q);
void SeqQueuePop(SeqQueue* q);
void SeqQueuePush(SeqQueue* q, SeqQueueType value);

void SeqQueueInit(SeqQueue* q);

#endif
