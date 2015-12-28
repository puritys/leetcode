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


TEST(onlyOne, success) {
    int size = 10;
    vector<vector<char>> V {{'O'}};
    Solution *obj = new Solution();
    obj->solve(V);
    ASSERT_EQ('O', V[0][0]);

}

TEST(normal, success) {
    int size = 10;
    vector<vector<char>> V {{'X','X','X','X'}, {'X','O','O','X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    Solution *obj = new Solution();
    obj->solve(V);
    print(V);
    ASSERT_EQ('X', V[0][0]);
    ASSERT_EQ('O', V[3][1]);

}



int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
