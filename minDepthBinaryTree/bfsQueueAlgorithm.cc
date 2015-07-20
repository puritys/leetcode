/*  BFS (queue)  breadth first search */
#include "algorithm.h"
#include <queue>
#include <map>
#include <iostream>


int bfsQueueAlgorithm(struct TreeNode* root) {
    std::queue<std::pair<struct TreeNode *, int> > queueHead;
    std::pair<struct TreeNode *, int> p;
    int depth = 1;
    if (!root) return 0;
    while (root) {
        if (!root->left && !root->right) return depth;

        if (root->left) {
            queueHead.push(std::make_pair(root->left, depth + 1));
        }
        if (root->right) {
            queueHead.push(std::make_pair(root->right, depth + 1));
        }
        p = queueHead.front();
        queueHead.pop();
        root = p.first;
        depth = p.second;
    }
    return depth;
}

