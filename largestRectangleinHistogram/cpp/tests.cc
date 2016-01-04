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
    vector<int> height {};
    int ret = obj->largestRectangleArea(height);
    ASSERT_EQ(0, ret);

}


TEST(simple, success) {
    Solution *obj = new Solution();
    vector<int> height {2,1,5,6,2,3};
    int ret = obj->largestRectangleArea(height);
    ASSERT_EQ(10, ret);

}

TEST(normal, success) {
    Solution *obj = new Solution();
    vector<int> height {1,1};
    int ret = obj->largestRectangleArea(height);
    ASSERT_EQ(2, ret);

}

TEST(normal2, success) {
    Solution *obj = new Solution();
    vector<int> height {1};
    int ret = obj->largestRectangleArea(height);
    ASSERT_EQ(1, ret);

}

TEST(normal3, success) {
    Solution *obj = new Solution();
    vector<int> height {2,1,2};
    int ret = obj->largestRectangleArea(height);
    ASSERT_EQ(3, ret);
}

TEST(normal4, success) {
    Solution *obj = new Solution();
    vector<int> height {2,1,1,1,2,2,1};
    int ret = obj->largestRectangleArea(height);
    ASSERT_EQ(7, ret);
}


int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
