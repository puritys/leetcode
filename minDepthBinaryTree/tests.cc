//https://leetcode.com/problems/minimum-depth-of-binary-tree/
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

//TEST(empty, success) {
//    struct TreeNode *head;
//    int depth = minDepth(head); 
//    ASSERT_EQ(0, depth);
//}

TEST(one_test, success) {
    struct TreeNode *head;
    head = (struct TreeNode*) calloc(1, sizeof(struct TreeNode));
    head->val = 10;
    head->left = NULL;
    head->right = NULL;
    int depth = minDepth(head); 
    ASSERT_EQ(1, depth);
}



TEST(normal, success) {
    struct TreeNode *head;
    head = (struct TreeNode*) calloc(1, sizeof(struct TreeNode));
    int nums[10] = {6,4,5,3,1,9,10,2,7,8};
    addTree(&head, nums, 10);
//printf("value = %d \n", head->val);
    int depth = minDepth(head); 
    ASSERT_EQ(4, depth);
    free(head);
}

TEST(more, success) {
    struct TreeNode *head;
    head = (struct TreeNode*) calloc(1, sizeof(struct TreeNode));
    int nums[30] = {6,27,28,29,4,30,5,25,26,12,22,23,24,18,19,20,21,3,13,14,15,16,17,1,9,11,10,2,7,8};
    addTree(&head, nums, 30);
    int depth = minDepth(head); 
    ASSERT_EQ(4, depth);
    free(head);
}

int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
