
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void addTree(struct TreeNode **tree, int *nums, int length);
void addTree(struct TreeNode **tree, int num);
void updateTree();
void deleteTree();
void printTree(struct TreeNode *tree);
