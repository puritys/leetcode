// https://leetcode.com/problems/sort-list/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include "algorithm.h"



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


