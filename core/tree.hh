struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void addTree(struct TreeNode **tree, int *nums, int length);
void addTree(struct TreeNode **tree, int num);
void updateTree();
void deleteTree();
void printTree(struct TreeNode *tree);
