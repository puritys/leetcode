#include "algorithm.h"

void queueCreate(Queue *queue, int maxSize) {
    queue->vals = (int*) malloc (sizeof(int) * maxSize);
    queue->maxSize = maxSize;
    queue->end = queue->start = -1;
}

void queuePush(Queue *queue, int val) {
    int newEnd = queue->end + 1;
    if (newEnd >= queue->maxSize) newEnd = 0;
    if (newEnd != queue->start) { // Queue is not full.
        *(queue->vals + newEnd) = val;
        queue->end = newEnd;
        if (queue->start == -1) queue->start = queue->end;
    }
}

void queuePop(Queue *queue) {
    if (queue->start == queue->end) queue->end = queue->start = -1;
    else if (++(queue->start) >= queue->maxSize) queue->start = 0;
}

int queuePeek(Queue *queue) {
    if (queue->start != -1)  return *(queue->vals + queue->start);
    return 0;  
}

bool queueEmpty(Queue *queue) {
    return (queue->start == -1);
}

void queueDestroy(Queue *queue) {
    queue->end = queue->start = -1;
    free(queue->vals);
}

void queuePrint(Queue *queue) {/*{{{*/
    int end = queue->end + 1;
    int i = queue->start;
    if (end >= queue->maxSize) end = 0;
    if (queue->start != -1) {
        for (i; i != end; i++) {
            if (i >= queue->maxSize) i = 0;
            printf("val = %d \n", *(queue->vals + i));
        }
    }
}/*}}}*/

