#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "algorithm.h"


struct ListNode* sortListPartitionV1(struct ListNode* head) {/*{{{*/
    struct ListNode *left, *right, *tmp;
    if (head == NULL) return head;
    left = head;
    tmp = head;
    while(tmp != NULL) {
        right = tmp;
        tmp = tmp->next; 
    }
    sortPartListV1(left, right);
    return head;
}/*}}}*/

bool sortPartListV1(struct ListNode* left, struct ListNode* right) {/*{{{*/
    struct ListNode *part1, *part2, *mid;
    int tmp;
    int middleVal = right->val;
    if (left == right) return true;
    mid = left;
    part1 = left;
    while(1) {
        // Get a number large than next starting from left
        while(part1 != right && part1->val < middleVal) {
            mid = part1;
            part1 = part1->next;
        }
        if (part1 == right) return false;
        part2 = part1->next;

        // Get a number small than prev starting from left
        while(part2 != right && part2->val >= middleVal) {
            part2 = part2->next;
        }
        if (part2 == right) break;
        tmp = part2->val;
        part2->val = part1->val;
        part1->val = tmp;
    }
    tmp = part1->val;
    part1->val = middleVal;
    right->val = tmp;
    sortPartListV1(left, mid);
    sortPartListV1(part1->next, right);
    return true;
}/*}}}*/


