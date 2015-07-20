/*  DFS depth first search */
#include "algorithm.h"

bool depthRecursive(struct TreeNode* node, int nowDepth, int *minDepth) {
    if (nowDepth >= *minDepth) return false;
    if (!node->left && !node->right) {
        if (nowDepth < *minDepth) {
            *minDepth = nowDepth;
        }
    } else {
        if (node->left) {
            depthRecursive(node->left, nowDepth+1, minDepth);
        }
        if (node->right) {
            depthRecursive(node->right, nowDepth+1, minDepth);
        }
    }
    return true;
}

int minDepth(struct TreeNode* root) {
    int depth = INT_MAX;
    if (!root) return 0;
    depthRecursive(root, 1, &depth); 

    return depth;
}

int dfsAlgorithm(struct TreeNode* root) {
    return minDepth(root);
}


