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
    int len = 0;
    Solution *obj = new Solution();
    unordered_set<string> list;
    vector<string> s = {"hot","dot","dog","lot","log"};
    reverse(s.begin(), s.end());
    for (vector<string>::iterator it = s.begin(); it != s.end(); it++) {
        list.insert(*it);
    }
    len = obj->ladderLength("hit", "cog", list);
    ASSERT_EQ(5, len);
}

TEST(empty1, success) {
    int len = 0;
    Solution *obj = new Solution();
    unordered_set<string> list;
    vector<string> s = {"aaa","bbb"};
    reverse(s.begin(), s.end());
    for (vector<string>::iterator it = s.begin(); it != s.end(); it++) {
        list.insert(*it);
    }
    len = obj->ladderLength("hit", "cog", list);
    ASSERT_EQ(0, len);
}

TEST(empty2, success) {
    int len = 0;
    Solution *obj = new Solution();
    unordered_set<string> list;
    len = obj->ladderLength("hit", "cog", list);
    ASSERT_EQ(0, len);
}

TEST(normalBFS_v1, success) {
    int len = 0;
    SolutionBFS_v1 *obj = new SolutionBFS_v1();
    unordered_set<string> list;
    vector<string> s = {"hot","dot","dog","lot","log"};
    reverse(s.begin(), s.end());
    for (vector<string>::iterator it = s.begin(); it != s.end(); it++) {
        list.insert(*it);
    }
    len = obj->ladderLength("hit", "cog", list);
    ASSERT_EQ(5, len);
}

int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


