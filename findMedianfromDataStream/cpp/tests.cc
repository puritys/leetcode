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

bool getOneCase(FILE *f, int *expect, int nums[], int *numSize) {
    bzero(nums, 900);
    *numSize = 0;
    int v[100], index = -1, numIndex = -1;
    char n[90], c;
    bzero(n, 90);
    if (feof(f)) return false;

    while (!feof(f)) { 
        c = fgetc(f); 
        if (c == ' ') break;
        n[++index] = c;
    }
    *expect = atoi(n);
    bzero(n, 90);
    index = -1;
    while (!feof(f)) {
        c = fgetc(f);
        if (c == ' ' || c == '\n') {
            nums[++numIndex] = atoi(n);
            (*numSize)++;
            bzero(n, 90);
            index = -1;
            if (c == '\n') return true;
            continue;
        }
        n[++index] = c;
    }
    return false;
}

TEST(normal, success) {
    FILE *f = fopen("testData", "r");
    int ret, v[100], index = -1, expect = 0;
    int nums[900], numSize = 0;
    bool t;
    do {
        t = getOneCase(f, &expect, nums, &numSize);
        if (false == t) break;
//cout << "expect = "<< expect <<endl;
        MedianFinder *o = new MedianFinder();
        for (int i = 0; i < numSize;i++) o->addNum(nums[i]);
        double ret = o->findMedian();

        ASSERT_EQ(expect, ret);

    } while(t);
}


int main (int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
