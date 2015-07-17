#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "algorithm.h"

struct ListNode* sortList(struct ListNode* head) {/*{{{*/
    int i = 0;
    struct ListNode *right, *midNode, *secSubList;
    if (head == NULL || head->next == NULL) return head;
    right = head->next;
    midNode = head;
    while(right != NULL && right->next != NULL) {
        right = right->next;
        if (i % 2 == 0) midNode = midNode->next; 
        i++;
    }
    secSubList = midNode->next;
    midNode->next = NULL;
    return merge(sortList(head), sortList(secSubList));
}/*}}}*/

struct ListNode* merge(struct ListNode* left, struct ListNode* right) {/*{{{*/
    struct ListNode *part1, *part2, *newNode, *dNode;
    int tmp;
    newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    dNode = newNode;
    if (left == right) return left;
    while(1) {
        if (left == NULL) {
            while(right != NULL) {
                dNode->next = right;
                dNode = dNode->next;
                right = right->next;
            }
            break;
        } else if (right == NULL) {
            while(left != NULL) {
                dNode->next = left;
                dNode = dNode->next;
                left = left->next;
            }
            break;
        } else if (left->val < right->val) {
            dNode->next = left;
            dNode = dNode->next;
            left = left->next;
        } else {
            dNode->next = right;
            dNode = dNode->next;
            right = right->next;
        }
    }
    //printf("\nnew Node ");print(newNode);printf("\n");
    return newNode->next;
}/*}}}*/

