#include "algorithm.h"


//void queueCreate(Queue *queue, int maxSize) {
//    queue->val = maxSize;
//    queue->next = NULL;
//}
//
//
///* Push element x to the back of queue */
//void queuePush(Queue *queue, int element) {
//    Queue *newElm;
//    Queue *tmp;
//    tmp = queue;
//    newElm = (Queue *) malloc (sizeof(Queue));
//    newElm->val = element;
//    newElm->next = NULL;
//    while (tmp && tmp->next != NULL) {
//        tmp = tmp->next;
//    }
//    tmp->next = newElm;
//}
//
///* Removes the element from front of queue */
//void queuePop(Queue *queue) {
//    Queue *retElm, *purge;
//    Queue *tmp; tmp = queue;
//    if (tmp && tmp->next) {
//        purge = tmp->next;
//        retElm = tmp->next;
//        if (tmp->next->next) {
//            tmp->next = tmp->next->next;
//        } else {
//            tmp->next = NULL;
//        }
//        free(purge);
//    }
//}
//
///* Get the front element */
//int queuePeek(Queue *queue) {
//    Queue *retElm;
//    Queue *tmp; tmp = queue;
//    if (tmp && tmp->next) {
//        retElm = tmp->next;
//        return retElm->val;
//    }
//    return 0;  
//}
//
///* Return whether the queue is empty */
//bool queueEmpty(Queue *queue) {
//    Queue *tmp; tmp = queue;
//    if (tmp && tmp->next != NULL) {
//        return false;
//    }
//    return true;  
//}
//
///* Destroy the queue */
//void queueDestroy(Queue *queue) {
//    Queue *purge;
//    Queue *tmp; tmp = queue;
//
//    while (tmp && tmp->next) {
//        purge = tmp->next;
//        if (tmp->next->next) {
//            tmp->next = tmp->next->next;
//        } else {
//            tmp->next = NULL;
//        }
//        free(purge);
//    }
//}
//
//
//void queuePrint(Queue *queue) {
//    Queue *tmp; tmp = queue;
//    while (tmp && tmp->next) {
//        printf("val = %d \n", tmp->next->val);
//        tmp = tmp->next;
//    }
//
//}
//
