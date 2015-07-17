#include <stdio.h>
#include <stdlib.h>
#include "algorithm.h"



void insert(struct ListNode* node, int num) {
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = num;
    newNode->next = NULL;
    struct ListNode* tmp = node;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void print(struct ListNode* node) {
    struct ListNode *tmp;
    tmp = node;
    while(1) {
        printf("%d ", tmp->val);
        if (tmp->next == NULL) break;
        tmp = tmp->next;
    }
}


