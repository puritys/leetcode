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

TEST(empty, success) {
    Solution *obj = new Solution();
    string s = obj->countAndSay(0);

    ASSERT_EQ("", s);
}

TEST(num1, success) {
    Solution *obj = new Solution();
    string s = obj->countAndSay(1);
    ASSERT_EQ("1", s);
}

TEST(num2, success) {
    Solution *obj = new Solution();
    string s = obj->countAndSay(2);

    ASSERT_EQ("11", s);
}
TEST(num3, success) {
    Solution *obj = new Solution();
    string s = obj->countAndSay(3);

    ASSERT_EQ("21", s);
}

TEST(num4, success) {
    Solution *obj = new Solution();
    string s = obj->countAndSay(4);

    ASSERT_EQ("1211", s);
}

TEST(num5, success) {
    Solution *obj = new Solution();
    string s = obj->countAndSay(5);

    ASSERT_EQ("111221", s);
}
int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


