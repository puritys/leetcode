#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include <iostream>
#include <stack>
using namespace std;

//struct Queue {
//    Queue *next;
//    int val;
//};

typedef struct {
    int *vals;
    int maxSize, start, end;
} Queue;


void queueCreate(Queue *queue, int maxSize);
void queuePush(Queue *queue, int element);
void queuePop(Queue *queue);
int queuePeek(Queue *queue);
bool queueEmpty(Queue *queue);
void queueDestroy(Queue *queue);

void queuePrint(Queue *queue);

class QueueCpp {
    stack<int> input, output;
public:

    void push(int x);
    void pop(void);
    int peek(void);
    bool empty(void);
};
