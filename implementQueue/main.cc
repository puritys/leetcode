// https://leetcode.com/problems/implement-queue-using-stacks/
#include "algorithm.h"

int main () {
    int size = 10;
    Queue *q = (Queue*) malloc (sizeof(Queue));
    queueCreate(q, size); 
    queuePrint(q);

    printf( "is empty = %d\n",  queueEmpty(q));

    queuePush(q, 1);
    queuePush(q, 2);
    queuePush(q, 3);
    queuePrint(q);
    queuePop(q);
    queuePop(q);
//    queuePop(q);
    queuePrint(q);
//    printf( "is empty = %d\n",  queueEmpty(q));

    return 0;
}
