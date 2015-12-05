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
    vector<string> v = {"hot","dot","dog","lot","log"};
    unordered_set<string> wordList;
    for (auto it = v.begin(); it != v.end(); it++) {
        wordList.insert(*it);
    }

    auto ret = obj->findLadders("hit", "cog", wordList);

    ASSERT_EQ("hit", ret[1][0]);
    ASSERT_EQ("hot", ret[1][1]);
    ASSERT_EQ("dot", ret[1][2]);
    ASSERT_EQ("dog", ret[1][3]);
    ASSERT_EQ("cog", ret[1][4]);


}

TEST(simple, success) {
    Solution *obj = new Solution();
    vector<string> v = {"a","b","c"};
    unordered_set<string> wordList;
    for (auto it = v.begin(); it != v.end(); it++) {
        wordList.insert(*it);
    }

    auto ret = obj->findLadders("a", "c", wordList);

    ASSERT_EQ("a", ret[0][0]);
    ASSERT_EQ("c", ret[0][1]);


}

TEST(simple2, success) {
    string start;
    string end;
    unordered_set<string> wordList;
    readFile("testData/case7", start, end, wordList);
    Solution *obj = new Solution();

    auto ret = obj->findLadders(start, end, wordList);
    ASSERT_EQ("hot", ret[0][0]);
    ASSERT_EQ("dot", ret[0][1]);
    ASSERT_EQ("dog", ret[0][2]);


}



TEST(large, success) {
    string start;
    string end;
    unordered_set<string> wordList;
    readFile("testData/case1", start, end, wordList);
    Solution *obj = new Solution();

    auto ret = obj->findLadders(start, end, wordList);
    ASSERT_EQ("cet", ret[0][0]);
    ASSERT_EQ("cot", ret[0][1]);
    ASSERT_EQ("con", ret[0][2]);
    ASSERT_EQ("ion", ret[0][3]);
    ASSERT_EQ("inn", ret[0][4]);
    ASSERT_EQ("ins", ret[0][5]);
    ASSERT_EQ("its", ret[0][6]);
    ASSERT_EQ("ito", ret[0][7]);
    ASSERT_EQ("ibo", ret[0][8]);
    ASSERT_EQ("ibm", ret[0][9]);
    ASSERT_EQ("ism", ret[0][10]);
}
TEST(large2, success) {
    string start;
    string end;
    unordered_set<string> wordList;
    readFile("testData/case4", start, end, wordList);
    Solution *obj = new Solution();

    auto ret = obj->findLadders(start, end, wordList);
    ASSERT_EQ("magic", ret[4][0]);
    ASSERT_EQ("manic", ret[4][1]);
    ASSERT_EQ("mania", ret[4][2]);
    ASSERT_EQ("maria", ret[4][3]);
    ASSERT_EQ("marta", ret[4][4]);
    ASSERT_EQ("marty", ret[4][5]);

    ASSERT_EQ("magic", ret[3][0]);
    ASSERT_EQ("manic", ret[3][1]);
    ASSERT_EQ("mania", ret[3][2]);
    ASSERT_EQ("maria", ret[3][3]);
    ASSERT_EQ("marta", ret[3][4]);

}

TEST(startEqualEnd, success) {
    Solution *obj = new Solution();
    vector<string> v = {"hot","dot","dog","lot","log"};
    unordered_set<string> wordList;
    for (auto it = v.begin(); it != v.end(); it++) {
        wordList.insert(*it);
    }

    auto ret = obj->findLadders("hit", "hit", wordList);

    ASSERT_EQ("hit", ret[0][0]);

}

int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


