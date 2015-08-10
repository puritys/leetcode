#include "algorithm.h"

int Solution::getHeight(TreeNode *root) {
    if (!root) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

bool Solution::isBalanced(TreeNode* root) {
    if (!root) return true;
    int left, right;
    left = getHeight(root->left);
    right = getHeight(root->right);
    if (abs(left - right) > 1)  return false;

    return isBalanced(root->left) && isBalanced(root->right);
}
 

