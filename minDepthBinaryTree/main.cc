//https://leetcode.com/problems/minimum-depth-of-binary-tree/
#include "algorithm.h"
int main () {
    struct TreeNode *head;
    head = (struct TreeNode*) calloc(1, sizeof(struct TreeNode));
    int nums[10] = {6,4,5,3,1,9,10,2,7,8};
    head->val = 0;
    addTree(&head, nums, 10);
    //printTree(head);
    int depth = bfsAlgorithm(head);
    int depth = dfsAlgorithm(head);
    int depth = bfsQueueAlgorithm(head);

    printf("depth = %d", depth);
}
