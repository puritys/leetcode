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

TEST(normal_1, success) {
    int nums[5] = {1,2,3,4,5};
    ListNode *head = createNodes(nums, 5);

    Solution *s = new Solution();
    head = s->reverseKGroup(head, 2);
    ListNode *tmp = head;
    ASSERT_EQ(2, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(1, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(4, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(3, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(5, tmp->val);

}

TEST(normal2, success) {
    int nums[2] = {1,2};
    ListNode *head = createNodes(nums, 2);

    Solution *s = new Solution();
    head = s->reverseKGroup(head, 2);
    ListNode *tmp = head;
    ASSERT_EQ(2, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(1, tmp->val);
}


TEST(normal_k_3, success) {
    int nums[5] = {1,2,3,4,5};
    ListNode *head = createNodes(nums, 5);

    Solution *s = new Solution();
    head = s->reverseKGroup(head, 3);
    ListNode *tmp = head;
    ASSERT_EQ(3, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(2, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(1, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(4, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(5, tmp->val);

}

TEST(full_reverse, success) {
    int nums[5] = {1,2,3,4,5};
    ListNode *head = createNodes(nums, 5);


    Solution *s = new Solution();
    head = s->reverseKGroup(head, 5);
    ListNode *tmp = head;
    ASSERT_EQ(5, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(4, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(3, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(2, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(1, tmp->val);
}

TEST(complicate, success) {
    int nums[7] = {1,2,11,12,3,13,14};
    ListNode *head = createNodes(nums, 7);


    Solution *s = new Solution();
    head = s->reverseKGroup(head, 3);

    ListNode *tmp = head;
    ASSERT_EQ(11, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(2, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(1, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(13, tmp->val);
    tmp = tmp->next;
    ASSERT_EQ(3, tmp->val);
    tmp = tmp->next; ASSERT_EQ(12, tmp->val);
    tmp = tmp->next; ASSERT_EQ(14, tmp->val);



}



TEST(normal_no_reverse, success) {

    ListNode *head = NULL;
    Solution *s = new Solution();
    head = s->reverseKGroup(head, 1);
    ListNode *tmp = head;
    ASSERT_EQ(NULL, tmp);
}

TEST(empty, success) {
    ListNode *head = new ListNode(0);
    Solution *s = new Solution();
    head = s->reverseKGroup(head, 3);
    ListNode *tmp = head;
    ASSERT_EQ(NULL, tmp->next);
}




int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
