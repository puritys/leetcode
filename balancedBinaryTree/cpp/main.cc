#include "algorithm.h"



int main() {
    bool ret;
    TreeNode *root;
    root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);


    printTree(root);

    Solution *o = new Solution();
    ret = o->isBalanced(root);
    cout << "result = " << ret << endl;
    return 0;

}

