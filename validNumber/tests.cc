#include <stdio.h>

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

/*
 * Get a string which is inside the quotes.
*/
string getString(FILE *f) {
    string ret = "";
    char c;
    while (!feof(f)) {
        c = fgetc(f);
        if (c == '"') {
            while (1) {
                c = fgetc(f);
                if (c == '"') {
                    return ret;
                } else {
                    ret += c;
                }
            }
        }
    }
    return "";
}

TEST(normalTest, success) {
    bool expectRet, ret;
    Solution *obj = new Solution();
    string testStr = "", testStrRet;
    FILE *f = fopen("testData", "r");
    while (!feof(f)) {
        testStr = getString(f);
        testStrRet = getString(f);
        if (testStrRet == "true") {
            expectRet = true;
        } else {
            expectRet = false;
        }
        cout << "test : " << testStr << "  " << expectRet << endl;
        ret = obj->isNumber(testStr);
        ASSERT_EQ(expectRet, ret);
    }

 //   ASSERT_EQ(2, max);
}


int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
