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

TEST(empty, success) {
    int *nums = (int *) malloc (sizeof(int) * 10);
    int ret = firstMissingPositive(nums, 0);
    ASSERT_EQ(1, ret);

    int *nums2;
    ret = firstMissingPositive(nums2, 0);
    ASSERT_EQ(1, ret);
}

TEST(normal, success) {
    int *nums = (int *) malloc (sizeof(int) * 10);
    for (int i = 9; i >= 0; i--) {
        *(nums + i) = (i + 1);
    }
    *(nums + 5) = -1;
    int ret = firstMissingPositive(nums, 10);
    ASSERT_EQ(6, ret);
}

TEST(small, success) {
    int *nums = (int *) malloc (sizeof(int) * 2);
    *(nums) = 2;
    *(nums + 1) = 1;
    int ret = firstMissingPositive(nums, 2);
    ASSERT_EQ(3, ret);
}


TEST(ansInTheEnd, success) {
    int *nums = (int *) malloc (sizeof(int) * 10);
    for (int i = 0; i< 10; i++) {
        *(nums + i) = (i + 1);
    }
    *(nums + 9) = -1;
    int ret = firstMissingPositive(nums, 10);
    ASSERT_EQ(10, ret);
}

TEST(allPositive, success) {
    int *nums = (int *) malloc (sizeof(int) * 10);
    for (int i = 0; i< 10; i++) {
        *(nums + i) = (i + 1);
    }
    int ret = firstMissingPositive(nums, 10);
    ASSERT_EQ(11, ret);
}

TEST(large, success) {
    int max = 109;
    int *nums = (int *) malloc (sizeof(int) * max);
    for (int i = 0; i< max; i++) {
        *(nums + i) = (i + 1);
    }
    *(nums + 106) = -1;
    *(nums + 102) = 0;


    int ret = firstMissingPositive(nums, max);
    ASSERT_EQ(103, ret);
}

TEST(sameNumber, success) {
    int *nums = (int *) malloc (sizeof(int) * 5);
    *(nums) = 0;
    *(nums + 1) = 2;
    *(nums + 2) = 2;
    *(nums + 3) = 1;
    *(nums + 4) = 1;

    int ret = firstMissingPositive(nums, 5);
    ASSERT_EQ(3, ret);
}

int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
