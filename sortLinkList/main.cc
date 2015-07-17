// https://leetcode.com/problems/sort-list/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include "algorithm.h"


void print(struct ListNode* node);

void insert(struct ListNode* node, int num) {
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = num;
    newNode->next = NULL;
    struct ListNode* tmp = node;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    assert(tmp->next == NULL);
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

int main () {
    int num[20];
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(node != NULL);
    node->val = 1;
    node->next = NULL;
    //srand(time(NULL));
    srand(1);
    for (int i = 2; i <= 200; i++) {
        int x = rand() % 100 + 1;
        insert(node, x);
    }

   // for (int i = 2; i <= 30293; i++) {
   //     int x = rand() % 3 + 1;
   //     insert(node, x);
   // }
    printf("Original Value: \n");print(node);
    printf("\n");
    sortList(node);
    //sortListPartitionV1(node);

    printf("\nResult: \n");
    print(node);
    return 0;
}


