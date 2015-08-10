#include "algorithm.h"
#include "gtest/gtest.h"
using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::Test;                                                                                                                           
using ::testing::TestCase;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::TestPartResult;
using ::testing::UnitTest;

TEST(normal, success) {
    TreeNode *root;
    root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    Solution *o = new Solution();
    ASSERT_EQ(true, o->isBalanced(root));
}

TEST(zero, success) {
    TreeNode *root;
    root = new TreeNode(0);
    Solution *o = new Solution();
    ASSERT_EQ(true, o->isBalanced(root));
}

TEST(null, success) {
    TreeNode *root = NULL;
    Solution *o = new Solution();
    ASSERT_EQ(true, o->isBalanced(root));
}

TEST(normal2, success) {
    TreeNode *root = NULL;
    root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution *o = new Solution();
    ASSERT_EQ(true, o->isBalanced(root));
}

TEST(normal3, success) {
    TreeNode *root = NULL;
    root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);

    Solution *o = new Solution();
    ASSERT_EQ(true, o->isBalanced(root));
}

TEST(normal4, success) {
    TreeNode *root = NULL;
    root = new TreeNode(1);
    root->left = new TreeNode(2);

    Solution *o = new Solution();
    ASSERT_EQ(true, o->isBalanced(root));
}

TEST(normal5, success) {
    TreeNode *root = NULL;
    root = new TreeNode(1);
    root->left = NULL;
    root->right = new TreeNode(2);
    root->right->left = NULL;
    root->right->right = new TreeNode(3);


    Solution *o = new Solution();
    ASSERT_EQ(false, o->isBalanced(root));
}



TEST(same, success) {
    TreeNode *root = NULL;
    root = new TreeNode(0);
    root->left = new TreeNode(3);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(4);

    Solution *o = new Solution();
    ASSERT_EQ(true, o->isBalanced(root));
}

TEST(duelNull, success) {
    TreeNode *root = NULL;
    root = new TreeNode(0);
    root->left = new TreeNode(3);
    root->right = new TreeNode(3);
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(4);

    Solution *o = new Solution();
    ASSERT_EQ(true, o->isBalanced(root));
}




int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
