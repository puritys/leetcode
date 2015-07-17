#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left = NULL;
    struct TreeNode *right = NULL;
};

void invert(struct TreeNode* node);
void invert(struct TreeNode* node) {
    if (node->left == NULL && node->right == NULL) {
        
    } else {
        struct TreeNode* tmpNode;
        tmpNode = node->right;
        node->right = node->left;
        node->left = tmpNode; 
    }
}
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) return root;
    invert(root);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}


void printTree(struct TreeNode* node) {
//    if (node->val) {
//        printf("%d", node->val);
//    printf("\n");
//
//    }
    if (node->left) {
        printf("%d  ", node->left->val);
        if (node->right) 
        printf("%d", node->right->val);
        printTree(node->left);
    }
    if (node->right) {
        printTree(node->right);
        printf("  ");

    }
    printf("\n");

}

int main() {
    int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n;
    n = sizeof(num) / sizeof(int);
    struct TreeNode *root;
    root = (TreeNode *) malloc(sizeof(TreeNode));
    struct TreeNode t; t.val = 1;
    root = &t;
    for (int i = 0; i < n; i++) {
    }
    struct TreeNode l1; //l1.val = 10;
    t.left = &l1;

    struct TreeNode r1; r1.val = 2;
    t.right = &r1;
//
//    struct TreeNode l2; l2.val = 8;
//    t.left->left = &l2;
//
//    struct TreeNode r2; r2.val = 9;
//    t.left->right = &r2;
//
//
//    struct TreeNode l3; l3.val = 18;
//    t.right->left = &l3;
//
//    struct TreeNode r3; r3.val = 21;
//    t.right->right = &r3;


    printTree(root);
    struct TreeNode* t2 = invertTree(root);
    printTree(t2);

    return 1;
}
