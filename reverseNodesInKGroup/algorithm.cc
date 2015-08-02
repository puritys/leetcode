#include "algorithm.h"


ListNode* Solution::reverseKGroup(ListNode *head, int k) {
    int size = 1, i;
    bool setHead = false, isEnd;
    ListNode *tmp, *now, *left = NULL, *right, *lastNode, *lastLeft = NULL;
    if (head == NULL) return head;

    //get list size
    tmp = head;
    while (tmp->next) { tmp = tmp->next; size++;}
    if (k > size) return head;

    tmp = head;
    head = NULL;
    for (i = 0; i < size; i++) {
        now = tmp;
        if (tmp->next) tmp = tmp->next;
        if (i % k == 0) {
            // End last round of k values
            if (setHead == false && i > 0) {
               head = lastNode;
               setHead = true;
            }
            if (lastLeft) lastLeft->next = lastNode;
            if (left) {left->next = now; lastLeft = left;}
            left = now;
            isEnd = true;
            if (i + k > size) break;
        } else {
            now->next = lastNode;
            isEnd = false;
        }
        lastNode = now;
    }
    if (isEnd == false) {
        left->next = NULL;
        if (lastLeft )lastLeft->next = now;
    }
    if (head == NULL) head = lastNode;
    return head;
}
