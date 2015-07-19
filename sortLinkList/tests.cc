#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
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


TEST(sortList, success) {/*{{{*/
    int num[10] = {6, 9, 7, 2, 10, 5, 1, 4, 8,3};
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(node != NULL);
    node->val = num[0];
    node->next = NULL;
    for (int i = 1; i < 10; i++) {
        insert(node, num[i]);
    }

    node = sortList(node);
    for (int i = 1; i <= 10; i++) {
        ASSERT_EQ(i, node->val);
        node = node->next;
    }
}/*}}}*/

TEST(sortListPartitioin, success) {/*{{{*/
    int num[10] = {6, 9, 7, 2, 10, 5, 1, 4, 8,3};
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(node != NULL);
    node->val = num[0];
    node->next = NULL;
    for (int i = 1; i < 10; i++) {
        insert(node, num[i]);
    }

    sortListPartitionV1(node);
    for (int i = 1; i <= 10; i++) {
        ASSERT_EQ(i, node->val);
        node = node->next;
    }
}/*}}}*/



int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}                 


