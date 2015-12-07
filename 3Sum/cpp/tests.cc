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


TEST(simple, success) {
    Solution *obj = new Solution();
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    auto ret = obj->threeSum(nums);
    print(ret);
    ASSERT_EQ(-1, ret[0][0]);
    ASSERT_EQ(0, ret[0][1]);
    ASSERT_EQ(1, ret[0][2]);
    ASSERT_EQ(-1, ret[1][0]);
    ASSERT_EQ(-1, ret[1][1]);
    ASSERT_EQ(2, ret[1][2]);

}

TEST(normal, success) {
    Solution *obj = new Solution();
    vector<int> nums = {-5,-4,0,1,2,3,4,5,6};

    auto ret = obj->threeSum(nums);
    print(ret);
    ASSERT_EQ(-4, ret[0][0]);
    ASSERT_EQ(1, ret[0][1]);
    ASSERT_EQ(3, ret[0][2]);
    ASSERT_EQ(-4, ret[1][0]);
    ASSERT_EQ(0, ret[1][1]);
    ASSERT_EQ(4, ret[1][2]);

}

//TEST(large, success) {
//    Solution *obj = new Solution();
//    vector<int> nums = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
//
//    auto ret = obj->threeSum(nums);
//    print(ret);
////    ASSERT_EQ(-1, ret[0][0]);
//}


int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


