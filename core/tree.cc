#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

void addTree(struct TreeNode **tree, int *nums, int length) {
    int i = 0;
    while(i < length) {
        addTree(tree, *(nums + i));
        i++;
    }
}

void addTree(struct TreeNode **tree, int newVal) {
    struct TreeNode *tmp, *newNode;
    newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = newVal;
    newNode->left = NULL;
    newNode->right = NULL;
    int val;
    if (!(*tree)) {
        (*tree) = newNode;
    } else {
        tmp = *tree;
        while(1) {
            val = tmp->val;
            if (newVal < val) {
                if (tmp->left == NULL) {tmp->left = newNode; break;}
                tmp = tmp->left;
            } else {
                if (tmp->right == NULL) {tmp->right = newNode; break;}
                tmp = tmp->right;
            }
        }
    }
}

void printTree(struct TreeNode *tree) {
    if (tree) {
        printTree(tree->left);
        printf("%d\n", tree->val);
        printTree(tree->right);
    }
}

