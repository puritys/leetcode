/*  BFS  breadth first search */
#include "algorithm.h"

struct queen {
    struct TreeNode *node;
    struct queen *next = NULL;
    int depth;
};

bool addQueen(struct queen *queens, struct TreeNode *next, int depth) {
    struct queen *tmp;
    struct queen *d = (struct queen*) malloc (sizeof(struct queen));
    d->depth = depth;
    d->node = next;
    tmp = queens;
    while (tmp && tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = d;
    return true;
}

struct TreeNode* getQueenFromTop(struct queen **queen, int *depth) {
    struct TreeNode *d;
    if (!(*queen)->next) {return d;}
    d = (*queen)->next->node;
    *depth = (*queen)->next->depth;
    *queen = (*queen)->next;
    return d;
}

int bfsAlgorithm(struct TreeNode* root) {
    struct queen *queenHead;
    queenHead = (struct queen *) malloc (sizeof(struct queen));
    int depth = 1;
    if (!root) return 0;
    while (root) {
        if (!root->left && !root->right) return depth;
        if (root->left) {
            addQueen(queenHead, root->left, depth + 1);
        }
        if (root->right) {
            addQueen(queenHead, root->right, depth + 1);
        }
        root = getQueenFromTop(&queenHead, &depth);
    }
    return depth;
}

