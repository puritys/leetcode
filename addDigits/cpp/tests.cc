#include "solution.h"
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
    Solution *obj = new Solution();
    int ret = obj->addDigits(38);
    ASSERT_EQ(2, ret);
}

TEST(normal2, success) {
    Solution *obj = new Solution();
    int ret = obj->addDigits(1682);
    ASSERT_EQ(8, ret);
}

TEST(normal3, success) {
    Solution *obj = new Solution();
    int ret = obj->addDigits(4359);
    ASSERT_EQ(3, ret);
}

TEST(normal4, success) {
    Solution *obj = new Solution();
    int ret = obj->addDigits(19);
    ASSERT_EQ(1, ret);
}


int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


