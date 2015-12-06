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

void testCase(string filePath) {
    vector<int> nums;
    vector<int> ret;
    vector<int> ans;
    int target;

    readFile(filePath, nums, target, ans);
    Solution *obj = new Solution();
    ret = obj->twoSum(nums, target);

    ASSERT_EQ(ans[0], ret[0]);
    ASSERT_EQ(ans[1], ret[1]);
}

TEST(testAll, success) {
    testCase("testData/case1");
    testCase("testData/case2");
    testCase("testData/case3");
    testCase("testData/case4");




}

int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


